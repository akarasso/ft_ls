CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

NAME	= ft_ls

HEADERS	= ./includes 

SOURCES	= ./srcs/main.c				./srcs/ls/ls_print_struct.c		./srcs/lst/ls_lst_bubblesort.c			\
	./srcs/lst/ls_lst_free.c		./srcs/lst/ls_lst_push.c		./srcs/lst/ls_lst_swap.c			\
	./srcs/parser/parse_files.c		./srcs/parser/parse_options.c		./srcs/parser/parser.c				\
	./srcs/print/ls_print.c			./srcs/print/ls_push.c			./srcs/print/ls_strpush.c			\
	./srcs/print/print_acl.c		./srcs/print/print_clink.c		./srcs/print/print_date.c			\
	./srcs/print/print_grp_user.c		./srcs/print/print_header.c		./srcs/print/print_min_maj.c			\
	./srcs/print/print_name.c		./srcs/print/print_right_group.c	./srcs/print/print_right_other.c		\
	./srcs/print/print_right_user.c		./srcs/print/print_rights.c		./srcs/print/print_size.c			\
	./srcs/print/print_sym_link.c		./srcs/print/print_type.c		./srcs/sort/sort_accesstime.c			\
	./srcs/sort/sort_ascii.c		./srcs/sort/sort_createtime.c		./srcs/sort/sort_modtime.c			\
	./srcs/sort/sort_size.c			./srcs/utils/ft_nbr_len.c		./srcs/utils/ft_strchr.c			\
	./srcs/utils/ft_strcmp.c		./srcs/utils/ft_strlen.c		./srcs/utils/get_acl_info.c			\
	./srcs/utils/get_files.c		./srcs/utils/get_fullpath.c		./srcs/utils/get_lstat.c			\
	./srcs/utils/get_user_info.c		./srcs/utils/ls_pow.c			

OBJ	= $(SOURCES:.c=.o)

HEADER_LIST	= $(addprefix -I,$(HEADERS))

all	: $(NAME)

%.o	: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(HEADER_LIST) -c -o $@ $<

$(NAME)	: $(OBJ)
	$(CC) $(CFLAGS) $(HEADER_LIST) -o $(NAME) $(OBJ)

clean	: 
	rm -f $(OBJ)

re	: fclean all

fclean	: clean
	rm -f $(NAME)

