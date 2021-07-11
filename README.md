# get_next_line


![image](https://user-images.githubusercontent.com/46234386/125183053-2cb02580-e24e-11eb-8f36-aafe25905b43.png)


# GET_next_line

```
int get_next_line(int fd, char **line);
```

![image](https://user-images.githubusercontent.com/46234386/122664051-de24e380-d1d9-11eb-8dd2-5412d3b3d701.png)



*  Calling your function get_next_line in a loop will then allow you to read the text available on a file descriptor one line at a time until the EOF.
* Make sure that your function behaves well when it reads from a file and when it reads from the standard input.
*  libft is not allowed for this project. You must add a get_next_line_utils.c file which will contain the functions that are needed for your get_next_line to work.
* • Your program must compile with the flag -D BUFFER_SIZE=xx. which will be used as the buffer size for the read calls in your get_next_line. This value will be modified by your evaluators and by moulinette. 
*  Compilation will be done this way : gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c 
* Your read must use the BUFFER_SIZE defined during compilation to read from a file or from stdin. 
*  In the header file get_next_line.h you must have at least the prototype of the function get_next_line.
