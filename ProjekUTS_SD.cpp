#include <iostream>
using namespace std;

struct data_cafe
{
    string name;
    int jumlah;
    double price;
    data_cafe *next;
};
data_cafe *head;

struct menu
{
    string nama;
    int harga;
} makanan[3], minuman[3];

// memasukkan menu-menu makanan dan harganya
void Makanan()
{
    makanan[0].nama = "French Fries";
    makanan[0].harga = 25000;
    makanan[1].nama = "Dimsum";
    makanan[1].harga = 15000;
    makanan[2].nama = "Churros";
    makanan[2].harga = 20000;
}

// memasukkan menu-menu makanan dan harganya
void Minuman()
{
    minuman[0].nama = "Ice Caffe Latte";
    minuman[0].harga = 25000;
    minuman[1].nama = "Ice Tea";
    minuman[1].harga = 10000;
    minuman[2].nama = "Avocado Juice";
    minuman[2].harga = 20000;
}

// menampilkan menu makanan
void daftar_makanan()
{
    Makanan();
    cout << endl;
    cout << endl;
    cout << "======== Daftar Makanan =========="<<endl;
    cout << "No. \tNama Makanan\t\tHarga"<<endl;
    cout << "------------------------------------"<<endl;

    for (int i = 0; i < size(makanan); i++)
    {
        cout << i + 1 << ". \t" << makanan[i].nama << "\t\t" << makanan[i].harga << endl;
    }
}

// menampilkan menu minuman
void daftar_minuman()
{
    Minuman();
    cout << endl;
    cout << endl;
    cout << "======== Daftar Minuman ==========" <<endl;
    cout << "No. \tNama minuman\t\tHarga" <<endl;
    cout << "------------------------------------" <<endl;

    for (int i = 0; i < size(minuman); i++)
    {
        cout << i + 1 << ". \t" << minuman[i].nama << "\t\t" << minuman[i].harga << endl;
    }
}

// menampilkan daftar menu
void display_menu(string menu)
{
    char input;
    while (!(input == 'y' || input == 'Y'))
    {
        if (menu == "makanan")
        {
            daftar_makanan();
        }
        else if (menu == "minuman")
        {
            daftar_minuman();
        }
        cout << endl;
        cout << "Kembali? (y/n) : " ;
        cin >> input;
    }
}

// Menghitung total harga
double total_price()
{
    double total_harga = 0;
    data_cafe *current = head;
    while (current != NULL)
    {
        total_harga += current -> price * current-> jumlah;
        current = current -> next;
    }
    return total_harga;
}

// menampilkan daftar pesanan
void display_order()
{
    double total_harga = 0;
    char input;
    data_cafe *current = head;
    while (!(input == 'y' || input == 'Y'))
    {
        if (current == NULL)
        {
            cout << endl;
            cout << "Anda belum memesan apapun" <<endl;
        }
        else
        {
            int i = 1;
            cout << "\n\nDaftar Pesanan" <<endl;
            cout << "No. \tNama \t\tHarga\t\tSatuan\t\tJumlah" <<endl;
            cout << "-----------------------------------------------" <<endl;
            while (current != NULL)
            {
                cout << i << "\t" << current->name << "\t\t" << current->price << "\t\t";
                cout << current->jumlah << "\t\t" << current->price * current->jumlah <<endl<<endl;
                current = current->next;
            }
            cout << "-----------------------------------------------\n";

            cout << "Total harga : " << total_price();
        }
        cout << "\n\nKembali? (y/n) : " ;
        cin >> input;
        cout << endl;
    }
}

// mencari posisi terakhir linked list
data_cafe *find_order()
{
    data_cafe *current = head;
    data_cafe *prev = new data_cafe();
    if (current != NULL)
    {
        do
        {
            prev = current;
            current = current -> next;
        } while (current != NULL);
        return prev;
    }
    return NULL;
}

void display_option();
// menambahkan pesanan
void place_order(string menu)
{
    int order_num;
    char choose = 'y';
    data_cafe *current = find_order();
    while (choose == 'Y' || choose == 'y')
    {
        data_cafe *temp = new data_cafe();
        if (menu == "makanan")
        {
        opsi_makanan:
            daftar_makanan();
            cout << "---------------------------------" <<endl;
            cout << "99.Kembali" <<endl;
            cout << "Pilihlah makanan (1/2/3/99) : ";
            cin >> order_num;
            switch (order_num)
            {
            case 1:
            case 2:
            case 3:
                temp-> name = makanan[order_num - 1].nama;
                temp-> price = makanan[order_num - 1].harga;
                cout << "Masukan Jumlah Makanan : ";
                cin >> temp->jumlah;
                break;
            case 99:
                display_option();
                break;
            default:
                cout << "Tidak ada di menu, silahkan pilih yang ada di menu!";
                goto opsi_makanan;
                break;
            }
        }
        else if (menu == "minuman")
        {
        opsi_minuman:
            daftar_minuman();
            cout << "---------------------------------" <<endl;
            cout << "99.Kembali" <<endl;
            cout << "Pilihlah minuman (1/2/3/99) : ";
            switch (order_num)
            {
            case 1:
            case 2:
            case 3:
                temp-> name = minuman[order_num - 1].nama;
                temp-> price = minuman[order_num - 1].harga;
                cout << "Masukan Jumlah Minuman : ";
                cin >> temp -> jumlah;
                break;
            case 99:
                display_option();
                break;
            default:
                cout << "Tidak ada di menu, silahkan pilih yang ada di menu!";
                goto opsi_minuman;
                break;
            }
        }
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            current = head;
        }
        else
        {
            current->next = temp;
            current = current->next;
        }
        cout << "Tambah Pesanan (y/n)? : ";
        cin >> choose;
    }
}

// menampilkan pilihan program
void display_option()
{
    int choice;
    cout << "========================================" <<endl;
    cout << "Pilih salah satu dari pilihan berikut:" <<endl;
    cout << "1. Menu Makanan" <<endl;
    cout << "2. Menu Minuman" <<endl;
    cout << "3. Pesan Makanan" <<endl;
    cout << "4. Pesan Minuman" <<endl;
    cout << "5. Tampilkan Pesanan" <<endl;
    cout << "6. Keluar" <<endl;
    cout << "Pilihan (1/2/3/4/5/6) : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        display_menu("makanan");
        break;
    case 2:
        display_menu("minuman");
        break;
    case 3:
        place_order("makanan");
        break;
    case 4:
        place_order("minuman");
        break;
    case 5:
        display_order();
        break;
    case 6:
        cout << "Program berhenti";
        exit(0);
    default:
        cout << "Tidak ada pilihan, silahkan pilih pilihan yang ada";
    }
}

int main()
{
    cout << "========================================" <<endl;
    cout << "                CAFETARIA               " <<endl;
    cout << "  Jalan. Ronggo Waluyo No. 72 Karawang  " <<endl;
    while (true)
    {
        display_option();
    }
    return 0;
}