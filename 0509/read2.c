#include <stdio.h>
#include <string.h>
void read_second_line(char* arr, int max_size) {
	char* start = "option: ";
	int i=0;
	for(; i < max_size && arr[i] != '\n'; i++) {}
	arr[i] = 0;
	printf("%s\n", arr + strlen(start));
}
int main(int argc, char* argv[])
{
	FILE *fp;
	fp = fopen(argv[1], "r");
	
	int pos = 0;
	int line = 0;
	int read_len =0;
	char buf[1024];
	

	while((read_len = fread(&buf, sizeof(char), 1024,fp)) >0) {
		for(int i=0; i < read_len; i++) {
			if (buf[i] == '\n') {
				line++;
				if(line == 1) {
					char* ptr = buf + i + 1;
					read_second_line(ptr, read_len -1);
					fclose(fp); return 0;
				}		
			}
		}
	}
	fclose(fp);
}
