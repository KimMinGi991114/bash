#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	FILE *fp;
	char* line1 = argv[2];
	int line;
	line = atoi(line1);
	char* start = argv[3];
	int lineCnt = 0;
	char buffer[2000];
	if(argc != 4) {
		fprintf(stderr, "사용법: %s 파일이름, 라인수, 문자열\n", argv[0]);
		return 1;
	}
	
	if((fp = fopen(argv[1], "rb")) != NULL){
		while(fgets(buffer, 2000, fp) != NULL){
			lineCnt++;
			if (lineCnt == line) {
				printf("%s\n", strtok(buffer, start));
				break;
			}	
		}
	}
	fclose(fp);
	
	return 0;
}

