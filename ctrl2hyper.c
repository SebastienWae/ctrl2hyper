#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <linux/input.h>

int read_event(struct input_event *event) {
	return fread(event, sizeof(struct input_event), 1, stdin) == 1;
}

void write_event(const struct input_event *event) {
	if (fwrite(event, sizeof(struct input_event), 1, stdout) != 1) {
		exit(EXIT_FAILURE);
	}
}

int main() {
	struct input_event input;
	setbuf(stdin, NULL), setbuf(stdout, NULL);

	while (read_event(&input)) {
		if (input.type == EV_MSC && input.code == MSC_SCAN) {
			continue;
		}

		if (input.type == EV_KEY && input.code == KEY_LEFTCTRL) {
			struct input_event lctrl = {.type = EV_KEY, .code = KEY_LEFTCTRL, .value = input.value};
			struct input_event lmeta = {.type = EV_KEY, .code = KEY_LEFTMETA, .value = input.value};
			struct input_event lalt = {.type = EV_KEY, .code = KEY_LEFTALT, .value = input.value};
			write_event(&lctrl);
			write_event(&lmeta);
			write_event(&lalt);
			continue;
		}

		write_event(&input);
	}
}

