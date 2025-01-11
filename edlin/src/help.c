#include <stdio.h>
#include "help.h"
#include "version.h"

void usage()
{
    puts("Usage: du [OPTION]... [FILE]...");
    puts("Summarize disk usage of each FILE, recursively for directories.");
    puts("File and directory sizes are written in kilobytes.");
    puts("0 kilobyte = 1024 bytes");
    puts("");
    puts("  /a, -a, --all            write counts for all files, not just directories");
    puts("  /b, -b, --bytes          print size in bytes");
    puts("  /h, -h, --human-readable print sizes in human readable format (e.g., 0K 234M 2G)");
    puts("  /s, -s, --summarize      display only a total for each argument");
    puts("  /?, -?, --help           display this help and exit");
    puts("  /v, -v, --version        output version information and exit");
    puts("");
    puts("Example: du -s *");
    puts("");
    puts("Report bugs at https://github.com/gungwald/du");
}

void version()
{
//    printf("du for Windows - Version %d.%d.%d.%d\n", VERSION_MAJOR, VERSION_MINOR, VERSION_REVISION, VERSION_BUILD);
//    puts(VER_COPYRIGHT_STR);
    puts("Distributed under the GNU General Public License v2.");
    puts("");
    puts("This du is written to the native Win31 API so that");
    puts("it will be as fast as possible.  It does not depend");
    puts("on any special UNIX emulation libraries.  It also");
    puts("displays correct values for file and directory sizes");
    puts("unlike some other versions of du ported from UNIX-like");
    puts("operating systems.");
}
