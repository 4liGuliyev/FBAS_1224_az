#include <iostream>
using namespace std;
int main() {
    FILE* fp, * ft;
    char secim;
    struct file {
        char ad[20];
        int nomre;
    };
    struct file f;
    char eded[50];
    long int size;
    fopen_s(&fp, "text.txt", "rb+");
    size = sizeof(f);
    while (true) {
        system("cls");
        cout << "1. Add Contact";
        cout << "\n2. All Contacts";
        cout << "\n3. Edit Contact";
        cout << "\n4. Delete Contact";
        cout << "\n5. Exit";
        cout << "\nReqem Daxil Edin: ";
        fflush(stdin);
        cin >> secim;
        switch (secim) {
        case '1':
            fseek(fp, 0, SEEK_END);
            system("cls");
            cout << "Adi Daxil Edin: ";
            cin >> f.ad;
            cout << "Nomre Daxil Edin: ";
            cin >> f.nomre;
            fwrite(&f, size, 1, fp);
            fflush(stdin);
            break;
        case '2':
            system("cls");
            rewind(fp);
            cout << "Ad\t\tNomre";
            while (fread(&f, size, 1, fp) == 1) {
                cout << "\n" << f.ad << "\t\t" << f.nomre;
            }
            cout << "\n";
            system("pause");
            break;
        case '3':
            system("cls");
            cout << "\nAdi Daxil Edin: ";
            cin >> eded;
            rewind(fp);
            while (fread(&f, size, 1, fp) == 1) {
                if (strcmp(f.ad, eded) == 0) {
                    cout << "Adi Daxil Edin: ";
                    cin >> f.ad;
                    cout << "Nomre Daxil Edin: ";
                    cin >> f.nomre;
                    fseek(fp, -size, SEEK_CUR);
                    fwrite(&f, size, 1, fp);
                    break;
                }
                else
                    cout << "";
            }
            fflush(stdin);
            break;
        case '4':
            system("cls");
            cout << "\nAdi Reqem Daxi Edin: ";
            cin >> eded;
            fopen_s(&ft, "text1.txt", "wb");
            rewind(fp);
            while (fread(&f, size, 1, fp) == 1)
                if (strcmp(f.ad, eded) != 0) {
                    fwrite(&f, size, 1, ft);
                }
            fclose(fp);
            fclose(ft);
            remove("text.txt");
            rename("text1.txt", "text.txt");
            fopen_s(&fp, "text.txt", "rb+");
            fflush(stdin);
            break;
        case '5':
            fclose(fp);
            cout << "Good Bye ;)";
            exit(0);
        }
    }
    system("pause");
    return 0;
}
