# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 11:55:58 by suzumaki          #+#    #+#              #
#    Updated: 2021/03/29 21:14:18 by suzumaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =	miniRT

HEADER = 	headers/light.h \
			headers/object.h \
			headers/camera.h \
			headers/vector.h \
			headers/minirt.h \
			gnl/get_next_line.h 

SRCS =		srcs/manage_errors.c \
			srcs/manages_1.c \
			srcs/manages_2.c \
			srcs/camera_list.c \
			srcs/parser.c \
			srcs/main.c \
			srcs/save_to_bmp.c \
			srcs/vec_oper.c \
			srcs/move_camera.c \
			srcs/quaternion_operations.c \
			srcs/t_sphere.c \
			srcs/light_list.c \
			srcs/obj.c \
			srcs/t_cylinder.c \
			srcs/minirt_utils.c \
			srcs/t_plane.c \
			srcs/t_square.c \
			srcs/t_triangle.c \
			srcs/vec_oper2.c \
			srcs/phong.c \
			srcs/quaternion_operations_2.c \
			srcs/raytrace_utils.c \
			srcs/move_camera2.c \
			srcs/rest_utils.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c

OBJS =		$(SRCS:.c=.o)
DEPS = 		$(SRCS:.c=.d) 

LIBFT =		libft
MLX =		minilibx_mms_20200219

CC :=		gcc
CFLAGS =	-Wall -Werror -Wextra
MLX_FLAGS =	libmlx.dylib -framework Metal -framework AppKit
LIB_FLAGS =	-L libft -lft
RM =		rm -f

all:		$(NAME)

-include $(DEPS)
DEPFLAGS	= -MMD -MF $(@:.o=.d)

%.o:		%.c
			$(CC) ${CFLAGS} $(DEPFLAGS) -O3 -c $< -o ${<:.c=.o} -g

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
			make -s -C $(MLX)
			mv $(MLX)/libmlx.dylib .
			make -s -C $(LIBFT)
			$(CC) $(CFLAGS) -O3 $(DEPFLAGS) $(LIB_FLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)
			$(RM) $(DEPS)
			make clean -C $(MLX)
			make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME)
			$(RM) libmlx.dylib
			$(RM) screenshot.bmp
			make fclean -C $(LIBFT)

re:		fclean all

norm:
			norminette $(LIBFT) gnl headers srcs

.PHONY:	all clean fclean re norm

