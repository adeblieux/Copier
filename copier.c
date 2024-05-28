#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For usleep

#define BUFFER_SIZE 4096 // Size of buffer for file copying

void printProgress(double percent); // Function prototype for progress printing

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 3){
        fprintf(stderr, "[!] Wrong argument count.\nUsage: Copier <Source File> <Destination File>\n");
        return 1; // Return error status
    }

    // Open source file for reading
    FILE *file1 = fopen(argv[1], "rb");
    if (file1 == NULL){
        fprintf(stderr, "[!] Cannot read file %s\n", argv[1]);
        return 1; // Return error status
    }

    // Open destination file for writing
    FILE *file2 = fopen(argv[2], "wb");
    if(file2 == NULL){
        fprintf(stderr, "[!] Cannot write to file %s\n", argv[2]);
        fclose(file1); // Close source file before exit
        return 1; // Return error status
    }

    char buffer[BUFFER_SIZE]; // Buffer for file copying
    size_t bytes_read; // Number of bytes read from source file

    // Read from source file and write to destination file until EOF
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file1)) > 0) {
        fwrite(buffer, 1, bytes_read, file2); // Write to destination file

        // Calculate progress
        long long int source_size, dest_size, cur_pos;
        fseek(file1, 0, SEEK_END); // Move to end of source file
        source_size = ftell(file1); // Get size of source file
        fseek(file2, 0, SEEK_END); // Move to end of destination file
        dest_size = ftell(file2); // Get size of destination file
        cur_pos = ftell(file1); // Get current position in source file
        double percent = (double)cur_pos / source_size; // Calculate progress
        printProgress(percent); // Print progress
    }

    // File copying completed
    printf("\nFile %s copied to file %s\n", argv[1], argv[2]);

    // Close files
    fclose(file1);
    fclose(file2);

    return 0; // Return success status
}

#define PBSTR "`-._,-'`-._,-'`-._,-'`-._,-'`-._,-'`-._,-'`-._,-'`-._,-'"
#define PBWIDTH 60

// Function to print progress
void printProgress(double percent) {
    int val = (int)(percent * 100); // Convert progress to percentage
    int lpad = (int)(percent * PBWIDTH); // Calculate number of '|' to print
    int rpad = PBWIDTH - lpad; // Calculate number of spaces to print
    printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, ""); // Print progress bar
    fflush(stdout); // Flush stdout to ensure progress bar is displayed
}
