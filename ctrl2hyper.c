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
			struct input_event f19 = {.type = EV_KEY, .code = KEY_F19, .value = input.value};
			write_event(&f19);
			continue;
		}

		write_event(&input);
	}
}

