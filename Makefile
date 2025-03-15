# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 14:51:15 by jperpect          #+#    #+#              #
#    Updated: 2025/03/14 22:39:12 by jperpct          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLGS = -Wall -Wextra -Werror

NAME = lsit.a

AR = ar rcs


Free_DIR = ../ft_free/
Free = $(Free_)ft_free.a


SRCS = list_f.c list_f_2.c list_free.c \


OBJECT = $(SRCS:.c=.o) 


CC = cc 

RM = rm -f

COUNT_FILE = count.txt

# Verifica se o arquivo existe; se não, cria com valor inicial 0
ifeq ($(wildcard $(COUNT_FILE)),)
    $(shell echo 0 > $(COUNT_FILE))
endif

COUNT = $(shell cat $(COUNT_FILE))



.SILENT:

all: git_free $(NAME)

git_free:
	@if [! -d "$(Free_DIR)"]; then \
		cd .. && git clone git@github.com:joao41-second/libft.git; \
		fi


$(NAME): $(OBJECT)
	@$(AR) $@ $(Free) $^
	@rm -f $(COUNT_FILE)

bonus: $(OBJECT_B) $(NAME)
	@ar rcs $(NAME) $(Free) $^
	@rm -f $(COUNT_FILE)


%.o:%.c $(NAME)
	@cc -c  $(FLGS) -o $@ $< 
	$(eval COUNT=$(shell echo $$(( $(COUNT) + 1 ))))

	# Salva o novo valor de COUNT no arquivo
	@$(MAKE) show_progress
	@echo $(COUNT) > $(COUNT_FILE)


show_progress:
	clear


	@PERCENT=$$(($(COUNT) * 100 / $(words $(SRCS)))); \
	PROG_LEN=$$(($$PERCENT / 10)); \
	echo -n "  $(NAME) ["; \
	for i in `seq 1 $$PROG_LEN`; do \
		echo -n "#"; \
	done; \
	for i in `seq $$PROG_LEN 10`; do \
		echo -n " "; \
	done; \
	echo "] $$PERCENT%"


clean:
	$(RM)  $(OBJECT) $(OBJECT_B)
		@rm -f $(COUNT_FILE)

fclean: clean
	$(RM) $(NAME)
		@rm -f $(COUNT_FILE)

re: fclean all
