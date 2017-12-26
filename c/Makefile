obj = test.o
all: $(obj)

$(obj): %.o: %.c
	cc $< -o $@

clean:
	find ./ -name "*~" -exec rm -rf {} \;
	find ./ -name "*.o" -exec rm -rf {} \;

.PHONY: all clean
