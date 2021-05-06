#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern ssize_t	ft_read(int fd, void *buf, size_t count);
extern size_t	ft_strlen(const char *s);
extern int		ft_strcmp(const char *s1, const char *s2);
extern char		*ft_strcpy(char *restrict dst, const char *src);
extern char		*ft_strdup(char *s);

void	draw_box(char box_title[6], int white_space_flag)
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
    printf("[ret] %zd\n[errno] %d\n", ft_write(-1, test_str, i), errno);
    printf("[ret] %zd\n", ft_write(1, test_str, i));

	draw_box("origin", 1);
    printf ("[ret] %zd\n[errno] %d\n", write(-1, test_str, i), errno);
    printf ("[ret] %zd\n", write(1, test_str, i));

	printf ("+--------------------------------------------+\n");
	printf ("|                  ft_read                   |\n");
	printf ("+--------------------------------------------+\n");
    int fd = open("main.c", O_RDONLY);
    char *test_str1 = calloc(sizeof(char), 1000); 
	printf("➡️  test_str: %s\n", test_str1);

	draw_box("myFunc", 0);
    printf("[ret] %zd\n[errno] %d\n", ft_read(fd, test_str1, 1000), errno);

	draw_box("origin", 1);
    printf("[ret] %zd\n[errno] %d\n", read(fd, test_str1, 1000), errno);

	printf ("+--------------------------------------------+\n");
    printf ("|                 ft_strlen                  |\n");
	printf ("+--------------------------------------------+\n");

    const char *test_str2 = "moboustt@1337.ma kjfjekje v ekjfekrjgekrger erkgkrejgkrjger gerkgjerkgner ";
    const char *test_str3 = "";

	draw_box("myFunc", 0);
    printf("[ret] %zu \n", ft_strlen(test_str2));
    printf("[errno] %d\n", errno);
	draw_box("origin", 1);
    printf("[ret] %lu \n", strlen(test_str2));
    printf("[errno] %d\n", errno);

	draw_box("myFunc", 0);
    printf("[ret] %zu \n", ft_strlen(test_str3));
    printf("[errno] %d\n", errno);
	draw_box("origin", 1);
    printf("[ret] %lu \n", strlen(test_str3));
    printf("[errno] %d\n", errno);


	printf ("+--------------------------------------------+\n");
    printf ("|                 ft_strcmp                  |\n");
	printf ("+--------------------------------------------+\n");

	draw_box("myFunc", 0);
    printf("[ret] %d\n", ft_strcmp("YOOO", ""));
	draw_box("origin", 1);
    printf("[ret] %d\n", strcmp("YOOO", ""));
	draw_box("myFunc", 0);
    printf("[ret] %d\n", ft_strcmp("YOOO", "YOOO"));
	draw_box("origin", 1);
    printf("[ret] %d\n", strcmp("YOOO", "YOOO"));
	draw_box("myFunc", 0);
    printf("[ret] %d\n", ft_strcmp("YOOO", "AAAAABBBBCCCCCDDDDD"));
	draw_box("origin", 1);
    printf("[ret] %d\n", strcmp("YOOO", "AAAAABBBBCCCCCDDDDD"));
	draw_box("myFunc", 0);
    printf("[ret] %d\n", ft_strcmp("", "AAAAABBBBCCCCCDDDDD"));
	draw_box("origin", 1);
    printf("[ret] %d\n", strcmp("", "AAAAABBBBCCCCCDDDDD"));

	printf ("+--------------------------------------------+\n");
    printf ("|                 ft_strcpy                  |\n");
	printf ("+--------------------------------------------+\n");

    const char	*src = "kefjkewbf kjbfejkbjkfb";
    char        *dst;

    if (!(dst = (char *) calloc(sizeof(char), 1000)))
        return (-1);

	draw_box("myFunc", 0);
    printf("[ret] %s\n", ft_strcpy(dst, src));
	draw_box("origin", 1);
    printf("[ret] %s\n", strcpy(dst, src));

	draw_box("myFunc", 0);
    printf("[ret] %s\n", ft_strcpy(dst, ""));
	draw_box("origin", 1);
    printf("[ret] %s\n", strcpy(dst, ""));

	draw_box("myFunc", 0);
    printf("[ret] %s\n", ft_strcpy(dst, "It works properly..."));
	draw_box("origin", 1);
    printf("[ret] %s\n", strcpy(dst, "It works properly..."));

    free(dst);

#if 1

	printf ("+--------------------------------------------+\n");
    printf ("|                 ft_strdup                  |\n");
	printf ("+--------------------------------------------+\n");

//    printf("[ret] %lu\n", strlen(strdup("moboustt")));
//    printf("[ret] %lu\n", strlen(ft_strdup("moboustt")));
    printf("[ret] %s\n", strdup("wohfwohfoewhfeowfheowbfeowfeowfeowijfoew"));
    printf("[ret] %s\n", ft_strdup("wohfwohfoewhfeowfheowbfeowfeowfeowijfoew"));
    printf("[ret] %s\n", strdup(""));  
    printf("[ret] %s\n", ft_strdup(""));  
#endif

    return (0);	
}
