#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BOX_FUNC 0
#define BOX_MINE 1
#define BOX_ORIG 2
#define LEN_TERM 30

void		hello(void);
ssize_t		ft_write(int fd, void const *buf, size_t nbyte);
ssize_t 	ft_read(int fd, void *d, size_t cont);

#if 0
extern  int ft_strlen(const char *s);
extern  int ft_strcmp(const char *s1, const char *s2);
extern  char * ft_strcpy(char *dst, const char  *src);
extern  ssize_t ft_write(int fd, const void *s, size_t cont);
extern  char   *ft_strdup(char *s);
#endif

void	draw_box(char *box_title, int white_space_flag)
{
	if (white_space_flag)
		printf("\t\t\t");
	printf ("+--------------------+\n");
	if (white_space_flag)
		printf("\t\t\t");
    printf ("|       %s       |\n", box_title);
	if (white_space_flag)
		printf("\t\t\t");
	printf ("+--------------------+\n");
}

int main (void)
{
	printf ("+--------------------------------------------+\n");
    printf ("|                  ft_write                  |\n");
	printf ("+--------------------------------------------+\n");
    char *test_str = "Hello world\n";
    int i = strlen(test_str);
	printf("➡️  test_str: %s", test_str);

	draw_box("myFunc", 0);
    printf("ret: %zd\nerrno: %d\n", ft_write(-1, test_str, i), errno);
    printf("ret: %zd\n", ft_write(1, test_str, i));

	draw_box("origin", 1);
    printf ("ret: %zd\nerrno: %d\n", write(-1, test_str, i), errno);
    printf ("ret: %zd\n", write(1, test_str, i));

	printf ("+--------------------------------------------+\n");
	printf ("|                  ft_read                   |\n");
	printf ("+--------------------------------------------+\n");
    int fd = open("main.c", O_RDONLY);
    char *test_str = calloc(sizeof(char) , 1000); 
	printf("➡️  test_str: %s", test_str);

	draw_box("myFunc", 0);
    printf("ret: %zd\nerrno: %d\n", ft_read(fd, test_str, 1000), errno);

	draw_box("origin", 1);
    printf("ret: %zd\nerrno: %d\n", read(fd, test_str, 1000), errno);

#if 0
	printf ("+--------------------------------------------+\n");
    printf ("|                 ft_strlen                  |\n");
	printf ("+--------------------------------------------+\n");

    const char *s = "moboustt@1337.ma kjfjekje v ekjfekrjgekrger erkgkrejgkrjger gerkgjerkgner ";
    const char *s1 = "";
    printf("strlen == > %lu \n", strlen(s));
    printf("ft_strlen == > %d \n", ft_strlen(s));
    printf("strlen == > %lu \n", strlen(s1));
    printf("ft_strlen == > %d \n", ft_strlen(s1));

    printf("--------Ft_Strcmp-------------\n\n");
    printf("ft_strcmp_v1 === > %d\n", ft_strcmp("YOOO", ""));
    printf("strcmp_v1 === > %d\n", strcmp("YOOO", ""));
    printf("ft_strcmp_v2 === > %d\n", ft_strcmp("YOOO", "YOOO"));
    printf("strcmp_v2 === > %d\n", strcmp("YOOO", "YOOO"));
    printf("ft_strcmp_v3 === > %d\n", ft_strcmp("YOOO", "AAAAABBBBCCCCCDDDDD"));
    printf("strcmp_v3 === > %d\n", strcmp("YOOO", "AAAAABBBBCCCCCDDDDD"));
    printf("ft_strcmp_v4 === > %d\n", ft_strcmp("", "AAAAABBBBCCCCCDDDDD"));
    printf("strcmp_v4 === > %d\n", strcmp("", "AAAAABBBBCCCCCDDDDD"));

    printf("--------Ft_strcpy------------\n\n");
    const char *src = "kefjkewbf kjbfejkbjkfb";
    char        *dst;
    if (!(dst = (char *) calloc(sizeof(char), 1000)))
        return (-1);
    printf("strcpy_v1 == > %s\n", strcpy(dst, src));
    printf("ft_strcpy_v1 == > %s\n", ft_strcpy(dst, src));

    printf("strcpy_v2 =:  %s\n", strcpy(dst, ""));
    printf("ft_strcpy_v2 =:  %s\n", ft_strcpy(dst, ""));

    free(str);

    printf ("----------Ft_strdup---------------\n\n");
    printf("strdup ==== > %lu\n", strlen(strdup("moboustt")));
    printf("ft_strdup ==== > %lu\n", strlen(ft_strdup("moboustt")));
    printf("strdup ==== > %s\n", strdup("wohfwohfoewhfeowfheowbfeowfeowfeowijfoew"));
    printf("strdup ==== > %s\n", ft_strdup("wohfwohfoewhfeowfheowbfeowfeowfeowijfoew"));
    printf("strdup ===== > %s\n", strdup(""));  
    printf("strdup ===== > %s\n", ft_strdup(""));  
#endif
    return (0);	
}
