CC     := gcc

OUT_DIR := build
SRC:= $(CURDIR)

include src/makefile

DEPS_O := $(patsubst %.c, $(OUT_DIR)/%.o,  $(DEPS))
INC    := -I$(SRC) 

$(info DEPS_O = $(DEPS_O))
$(info DEPS =   $(DEPS))
$(info SRC  = 	$(SRC))

main: $(OUT_DIR)/main.o $(DEPS_O)
		$(CC) $(INC) $^ -o $@

$(OUT_DIR)/%.o:%.c
	@mkdir -p $(@D)
	$(CC) $(INC) -c $^  -o $@


clean:
	rm -rf $(OUT_DIR)/* ;rm main
