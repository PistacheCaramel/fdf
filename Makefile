NAME = fdf
CC = gcc
RM = rm -rf
SRCSDIR = srcs
OBJSDIR = objs
SRCS = fdf.c main.c get_next_line.c get_next_line_utils.c libfunc.c draw_pixels.c render_frame.c scale.c set_null.c exit.c parse.c order.c fdf_assets.c mouse_handler.c checker.c
OBJS = ${SRCS:%.c=${OBJSDIR}/%.o}
NAMEBNS = fdf_bonus
OBJSBNSDIR = objs_bonus
SRCSBNSDIR = srcs_bonus
SRCSBNS = fdf_bonus.c main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c libfunc_bonus.c draw_pixels_bonus.c render_frame_bonus.c scale_bonus.c set_null_bonus.c exit_bonus.c parse_bonus.c order_bonus.c fdf_assets_bonus.c symetry_bonus.c mouse_handler_bonus.c symetry_asset_bonus.c
OBJSBNS = ${SRCSBNS:%.c=${OBJSBNSDIR}/%.o}

$(NAME): ${OBJS}
	$(CC) $(OBJS) -Wall -Wextra -Werror -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
${OBJS}: ${OBJSDIR}/%.o: ${SRCSDIR}/%.c
	mkdir -p ${OBJSDIR}
	$(CC) -I./includes/. -I/usr/include -Imlx_linux -g -O3 -c $< -o $@

$(NAMEBNS): ${OBJSBNS}
	$(CC) $(OBJSBNS) -Wall -Wextra -Werror -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAMEBNS)

${OBJSBNS}: ${OBJSBNSDIR}/%.o: ${SRCSBNSDIR}/%.c
	mkdir -p ${OBJSBNSDIR}
	$(CC) -I./includes_bonus/. -I/usr/include -Imlx_linux -g -O3 -c $< -o $@

all:	 ${NAME}

bonus:	${NAMEBNS}

clean:	
	 ${RM} ${OBJS}
	 ${RM} ${OBJSDIR}
	 ${RM} ${OBJSBNS}
	 ${RM} ${OBJSBNSDIR}

fclean:	clean 
	 ${RM} ${NAME}
	 ${RM} ${NAMEBNS}

re: fclean all

.PHONY: clean all fclean re bonus
