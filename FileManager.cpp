#include "FileManager.h"

void FileManager::reverseSentences(const string& filename){
    try{
        ifstream file(filename);
        if (!file.is_open()){
            throw runtime_error("Can't open file: " + filename);
        }

        string sentences[3];
        int count = 0;
        string line;

        while (count < 3 && getline(file, line, '.')){
            if (!line.empty()){
                sentences[count] = line + ".";
                count++;
            }
        }

        file.close();

        if (count == 0) {
            throw runtime_error("No sentences found in file");
        }

        cout << "Sentences in reverse order:" << endl;
        for (int i = count - 1; i >= 0; i--) {
            cout << sentences[i] << endl;
        }


    }
    catch(const exception& e){
        cout << "Error: " << e.what() << endl;
    }
}