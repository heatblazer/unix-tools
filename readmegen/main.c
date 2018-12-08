#include <stdio.h>

#define HEADER "< FILL WITH YOUR PROJECT NAME HERE>\r\n"

#define LINEMARK "=========================================\r\n"

#define BUILD "## Build:\r\n"

#define INSTALL "## Install:\r\n"

#define CODESNIPPET "```\r\n"      	\
            "./configure\r\n"   \
            "make clean\r\n"    \
            "make dep && make\r\n" \
            "make install\r\n"     \
            "```\r\n"
#define  PROGRAMMER "## Programmer:\r\n"

#define IMPORTANT "**IMPORTANT**\r\n"

#define BUILDPROCESS "*Build process\r\n*"				\
             "- Do something like `pjslib/build/ make`\r\n"

#define QTPROJ "## Qt project:\r\n"

#define OTHERS "## some project  howto:\r\n"				\
        "[link](link.md)\r\n"

#define TODO "[TODO](TODO.md)\r\n"

#define CONTACT "***\r\n"						\
        "<yourmail_at_example_dot_org>\r\n"


int main(void)
{
    FILE* fp  = fopen("README.md", "w");
    if (!fp)
    return -1;

    fprintf(fp, "%s\r\n", HEADER);
    fprintf(fp, "%s\r\n", LINEMARK);
    fprintf(fp, "%s\r\n", BUILD);
    fprintf(fp, "%s\r\n", INSTALL);
    fprintf(fp, "%s\r\n", CODESNIPPET);
    fprintf(fp, "%s\r\n", PROGRAMMER);
    fprintf(fp, "%s\r\n", IMPORTANT);
    fprintf(fp, "%s\r\n", BUILDPROCESS);
    fprintf(fp, "%s\r\n", QTPROJ);
    fprintf(fp, "%s\r\n", OTHERS);
    fprintf(fp, "%s\r\n", TODO);
    fprintf(fp, "%s\r\n", CONTACT);

    fflush(fp);
    fclose(fp);
    return 0;
}

