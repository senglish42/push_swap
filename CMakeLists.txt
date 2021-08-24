cmake_minimum_required(VERSION 3.17.5)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -gdwarf-3")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -gdwarf-3")

file(GLOB SRC libft/*.c src/*.c)

add_executable(push_swap libft ${SRC} main.c push_swap.h src/ft_param.c src/ft_pushswap.c src/ft_error.c src/ft_filllist.c src/ft_swaptwo.c src/ft_order.c src/ft_rotate.c src/ft_pushelem.c src/ft_re_rotate.c libft/ft_isdigit.c libft/ft_memcmp.c libft/ft_putstr_fd.c)