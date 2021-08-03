cmake_minimum_required(VERSION 3.17.5)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

file(GLOB SRC libft/*.c src/*.c)

add_executable(push_swap libft ${SRC} main.c push_swap.h src/ft_parse.c src/ft_compare.c libft/ft_isdigit.c libft/ft_memcmp.c libft/ft_putstr_fd.c)