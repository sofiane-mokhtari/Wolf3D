# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 22:52:47 by smokhtar          #+#    #+#              #
#    Updated: 2018/02/20 22:52:52 by smokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


name = wolf3d

flag = -Wall -Werror -Wextra

comp = -lmlx -framework OpenGL -framework AppKit

file =main\
		lecture\
		graph\
		utili\
		key\
		key2\
		print_tex\
		menu\

Src = $(addprefix srcs/, $(file))

src = $(addsuffix .c, $(Src))

lib = -lft -Llibft -lmlx -Lminilibx_macos

X = -I/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/

inc = -Iincludes -Ilibft/includes -Iminilibx

object = $(addsuffix .o, $(Src))

all: $(name)

$(name) :
	make -C libft/
	make -C minilibx_macos/
	gcc -o $(name) $(lib) $(X) $(comp) $(SRC) $(src) $(inc) $(flag)

e : 
	touch wolf3d
	rm wolf3d
	gcc -o $(name) $(lib) $(X) $(comp) $(SRC) $(src) $(inc) $(flag)

clean :
	make -C libft/ fclean
	make -C minilibx_macos/ clean
	rm -rf $(obj)

fclean : clean
	touch $(name)
	rm $(name)

re : fclean all