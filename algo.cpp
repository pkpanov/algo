#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <vector>
#include <algorithm>

#pragma warning( disable : 4996 )

#define READDIR_BUFFER_SIZE 0x10000

using namespace std;

int main( int argc, char *argv[] ) {

    HANDLE hDir;
    BOOL bRes;
    PFILE_ID_BOTH_DIR_INFO p, pfiDirInfo = NULL;
    WCHAR wszFileName[ MAX_PATH ];
    stack< wstring > st;
    vector< wstring > v;

    srand( ( unsigned int )time( NULL ) );

    if ( argc < 2 ) {

        printf( "Usage: algo.exe <path>\n\n" );
        goto exit;
    }

    swprintf( wszFileName, L"%S", argv[1] );

    pfiDirInfo = ( PFILE_ID_BOTH_DIR_INFO )malloc( READDIR_BUFFER_SIZE );
    if ( pfiDirInfo == NULL ) {
        printf( "Insufficient resources!\n" );
        goto exit;
    }

    st.push( wszFileName );

    while ( !st.empty() ) {

        wstring wszDirPath = st.top();
        st.pop();

        // printf( "Enumerating directory '%ws' ...\n", wszDirPath.c_str() );

        if ( wszDirPath[ wszDirPath.length() - 1 ] != L'\\' )
            wszDirPath += L'\\';

        hDir = CreateFileW( wszDirPath.c_str(),
                            FILE_LIST_DIRECTORY,
                            FILE_SHARE_READ | FILE_SHARE_WRITE |FILE_SHARE_DELETE,
                            NULL,
                            OPEN_EXISTING,
                            FILE_FLAG_BACKUP_SEMANTICS,
                            NULL );
        if ( hDir == INVALID_HANDLE_VALUE ) {

            printf( "CreateFile( '%ws' ) failed! Error = %d\n", wszDirPath.c_str(), GetLastError() );
            continue;
        }

        while ( true ) {

            bRes = GetFileInformationByHandleEx( hDir,
                                                 FileIdBothDirectoryInfo,
                                                 pfiDirInfo,
                                                 READDIR_BUFFER_SIZE );
            if ( !bRes ) break;

            p = pfiDirInfo;

            while ( true ) {

                if ( wcsncmp( p->FileName, L".", p->FileNameLength / sizeof( WCHAR ) ) &&
                     wcsncmp( p->FileName, L"..", p->FileNameLength / sizeof( WCHAR ) ) ) {

                    memset( wszFileName, 0, sizeof( wszFileName ) );
                    wcscpy( wszFileName, wszDirPath.c_str() );
                    wcsncat( wszFileName, p->FileName, p->FileNameLength / sizeof( WCHAR ) );

                    size_t nFileNameLen = wcslen( wszFileName );

                    if ( ( ( nFileNameLen >= 2 ) && ( wcsicmp( wszFileName + nFileNameLen - 2, L".c" ) == 0 ) ) ||
                         ( ( nFileNameLen >= 4 ) && ( wcsicmp( wszFileName + nFileNameLen - 4, L".cpp" ) == 0 ) ) ) {

                        v.push_back( wszFileName );
                    }

                    if ( p->FileAttributes & FILE_ATTRIBUTE_DIRECTORY ) {

                        st.push( wszFileName );
                    }
                }

                if ( p->NextEntryOffset > 0 ) {
                    p = ( PFILE_ID_BOTH_DIR_INFO ) ( ( PUCHAR )p + p->NextEntryOffset );
                } else {

                    break;
                }
            }
        }

        CloseHandle( hDir );
    }

    printf( "%ws\n", v[ rand() % v.size() ].c_str() );

exit:

    //printf("%d files have been processed\n", cnt);

    if ( pfiDirInfo != NULL )
        free( pfiDirInfo );

    return 0;
}
