cmake_minimum_required(VERSION 3.17.5)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -gdwarf-3")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -gdwarf-3")

file(GLOB SRC libft/*.c src/*.c)

#add_executable(push_swap libft ${BONUS} bonus/checker.c bonus/get_next_line.c bonus/get_next_line.h bonus/get_next_line_utils.c)
add_executable(push_swap libft ${SRC} push_swap.h src/ft_turns.c src/ft_three.c src/ft_sort.c src/ft_param.c src/ft_pushswap.c src/ft_error.c src/ft_filllist.c src/ft_swaptwo.c src/ft_order.c src/ft_min.c src/ft_rotate.c src/ft_sort_b.c src/ft_pushelem.c src/ft_re_rotate.c libft/ft_isdigit.c libft/ft_memcmp.c libft/ft_putstr_fd.c ${BONUS} bonus/ft_checker.c bonus/get_next_line.c bonus/ft_make.c bonus/main.c)