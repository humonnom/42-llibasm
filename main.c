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

void	move_to_next_func()
{
	char input[1];
	read(1, input, 1);
	system("clear");
}

int main (void)
{
	move_to_next_func();
	printf ("+--------------------------------------------+\n");
    printf ("|                  ft_write                  |\n");
	printf ("+--------------------------------------------+\n");
    char *test_str = "Hello world\n";
    int i = strlen(test_str);
	printf("➡️  test_str: %s", test_str);

	draw_box("myFunc", 0);
    printf("[ret] %zd\n[errno] %d\n", ft_write(1, test_str, i), errno);

	draw_box("origin", 1);
    printf ("[ret] %zd\n[errno] %d\n", write(1, test_str, i), errno);

	draw_box("myFunc", 0);
    printf("[ret] %zd\n[errno] %d\n", ft_write(-1, test_str, i), errno);

	draw_box("origin", 1);
    printf ("[ret] %zd\n[errno] %d\n", write(-1, test_str, i), errno);


	move_to_next_func();
	printf ("+--------------------------------------------+\n");
	printf ("|                  ft_read                   |\n");
	printf ("+--------------------------------------------+\n");
    int fd = open("ft_write.s", O_RDONLY);
    char *test_str1 = calloc(sizeof(char), 1000); 
	printf("➡️  test fd: %s\n", "ft_write.s");

	draw_box("myFunc", 0);
    printf("[ret] %zd\n[errno] %d\n", ft_read(fd, test_str1, 1000), errno);

	draw_box("origin", 1);
    printf("[ret] %zd\n[errno] %d\n", read(fd, test_str1, 1000), errno);

	fd = open("invalid_file_name", O_RDONLY);

	draw_box("myFunc", 0);
    printf("[ret] %zd\n[errno] %d\n", ft_read(fd, test_str1, 1000), errno);

	draw_box("origin", 1);
    printf("[ret] %zd\n[errno] %d\n", read(fd, test_str1, 1000), errno);

	move_to_next_func();
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


	move_to_next_func();
	printf ("+--------------------------------------------+\n");
    printf ("|                 ft_strcmp                  |\n");
	printf ("+--------------------------------------------+\n");

	draw_box("myFunc", 0);
    printf("[ret] %d\n", ft_strcmp("YOOO", ""));
    printf("[errno] %d\n", errno);
	draw_box("origin", 1);
    printf("[ret] %d\n", strcmp("YOOO", ""));
    printf("[errno] %d\n", errno);
	draw_box("myFunc", 0);
    printf("[ret] %d\n", ft_strcmp("YOOO", "YOOO"));
    printf("[errno] %d\n", errno);
	draw_box("origin", 1);
    printf("[ret] %d\n", strcmp("YOOO", "YOOO"));
    printf("[errno] %d\n", errno);
	draw_box("myFunc", 0);
    printf("[ret] %d\n", ft_strcmp("YOOO", "AAAAABBBBCCCCCDDDDD"));
    printf("[errno] %d\n", errno);
	draw_box("origin", 1);
    printf("[ret] %d\n", strcmp("YOOO", "AAAAABBBBCCCCCDDDDD"));
    printf("[errno] %d\n", errno);
	draw_box("myFunc", 0);
    printf("[ret] %d\n", ft_strcmp("", "AAAAABBBBCCCCCDDDDD"));
    printf("[errno] %d\n", errno);
	draw_box("origin", 1);
    printf("[ret] %d\n", strcmp("", "AAAAABBBBCCCCCDDDDD"));
    printf("[errno] %d\n", errno);

	move_to_next_func();
	printf ("+--------------------------------------------+\n");
    printf ("|                 ft_strcpy                  |\n");
	printf ("+--------------------------------------------+\n");

    const char	*src = "kefjkewbf kjbfejkbjkfb";
    char        *dst;

    if (!(dst = (char *) calloc(sizeof(char), 1000)))
        return (-1);

	draw_box("myFunc", 0);
    printf("[ret] %s\n", ft_strcpy(dst, src));
    printf("[errno] %d\n", errno);
	draw_box("origin", 1);
    printf("[ret] %s\n", strcpy(dst, src));
    printf("[errno] %d\n", errno);

	draw_box("myFunc", 0);
    printf("[ret] %s\n", ft_strcpy(dst, ""));
    printf("[errno] %d\n", errno);
	draw_box("origin", 1);
    printf("[ret] %s\n", strcpy(dst, ""));
    printf("[errno] %d\n", errno);

	draw_box("myFunc", 0);
    printf("[ret] %s\n", ft_strcpy(dst, "It works properly..."));
    printf("[errno] %d\n", errno);
	draw_box("origin", 1);
    printf("[ret] %s\n", strcpy(dst, "It works properly..."));
    printf("[errno] %d\n", errno);

    free(dst);

	move_to_next_func();
	printf ("+--------------------------------------------+\n");
    printf ("|                 ft_strdup                  |\n");
	printf ("+--------------------------------------------+\n");
	char *test_str_dup;

    printf("test_str: [%s]\n", "moboustt");

	draw_box("myFunc", 0);
	test_str_dup = strdup("moboustt");
    printf("[ret] %lu\n", strlen(test_str_dup));
    printf("[errno] %d\n", errno);
	free(test_str_dup);

	draw_box("origin", 1);
	test_str_dup = ft_strdup("moboustt");
    printf("[ret] %lu\n", strlen(test_str_dup));
    printf("[errno] %d\n", errno);
	free(test_str_dup);

    printf("test_str: [%s]\n", "wohfwohfoewhfeowfheowbfeowfeowfeowijfoew");

	draw_box("myFunc", 0);
	test_str_dup = strdup("wohfwohfoewhfeowfheowbfeowfeowfeowijfoew");
    printf("[ret] %s\n", test_str_dup);
    printf("[errno] %d\n", errno);
	free(test_str_dup);

	draw_box("origin", 1);
	test_str_dup = ft_strdup("wohfwohfoewhfeowfheowbfeowfeowfeowijfoew");
    printf("[ret] %s\n", test_str_dup);
    printf("[errno] %d\n", errno);
	free(test_str_dup);

    printf("test_str: [%s]\n", "");

	draw_box("myFunc", 0);
	test_str_dup = strdup("");
    printf("[ret] %s\n", test_str_dup);
    printf("[errno] %d\n", errno);
	free(test_str_dup);

	draw_box("origin", 1);
	test_str_dup = ft_strdup("");
    printf("[ret] %s\n", test_str_dup);
    printf("[errno] %d\n", errno);
	free(test_str_dup);
	
    return (0);	
}
