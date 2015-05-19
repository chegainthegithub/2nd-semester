#include "mydialog.h"
#include "ui_mydialog.h"
#include <QFileDialog>
#include <QStringList>
#include <QStringListModel>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
void qs(int* arr, int first, int last)
{
    int i = first, j = last, x = arr[(first + last) / 2];

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            if (arr[i] > arr[j]) swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        qs(arr, i, last);
    if (first < j)
        qs(arr, first, j);
}
vector<vector<int> > matrix_creator(int *true_arr, int num, int size)
{
    vector<vector<int> > matrix; // check for size < num needed
    vector <int> local_arr;
    int *arr = new int[num];
    int *full_arr = new int[size];
    for (int i = 0; i < num; i++)
        arr[i] = i + 1;
    for (int i = 0; i < size; i++)
        full_arr[i] = i + 1;	       //int full_arr[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int n, m;                          //int true_arr[8] = { 0, 1, 3, 5, 7, 9, 11, 13 };
    n = size - 1;
    int k = num - 1;
    int l = 0;
    for (int i = 0; i < num; i++)
        local_arr.push_back(true_arr[i]);
    matrix.push_back(local_arr);
    int i;
    while (true)
    {
        for (i = k; i >= 0; i--)
        {
            while (arr[i] < full_arr[n - l])
            {
                arr[i]++;
                for (int f = i + 1; f <= k; f++)
                    arr[f] = arr[i] + f - i;
                vector<int> local_arr1;
                for (int s = 0; s <= k; s++)
                    local_arr1.push_back(true_arr[arr[s] - 1]);
                matrix.push_back(local_arr1);
                for (int f = k; f >= i + 1; f--)
                {
                    while (arr[f] < full_arr[f + n - k])
                    {
                        ++arr[f];
                        vector<int> local_arr1;
                        for (int s = 0; s <= k; s++)
                            local_arr1.push_back(true_arr[arr[s] - 1]);
                        matrix.push_back(local_arr1);
                    }
                }
            }
            ++l;
        }
        if (i == -1)
            break;
    }
    return(matrix);
}
vector<int> the_arr(int All_Goods, int num, int Number_Trades, const char *name)
{
    int *True_arr1 = new int[All_Goods];
    for (int i = 0; i < All_Goods; i++)
        True_arr1[i] = i + 1;
    vector<vector<int> > Matrix_full = matrix_creator(True_arr1, num, All_Goods);
    int Great_limit = Matrix_full.size();
    int *Full_Arr = new int[Great_limit];
    for (int i = 0; i < Great_limit; i++)
        Full_Arr[i] = 0;
    int buffer;
    ifstream file(name, ios::in);
    file >> buffer; //
    file >> buffer; //
    for (int i = 1; i <= Number_Trades; i++)
    {
        int Trade_Goods = 0; //
        file >> Trade_Goods;
        if (num > Trade_Goods)//
        {
            for (int local4 = 0; local4 < Trade_Goods; local4++)
                file >> buffer;
            continue;
        }
        int *True_arr2 = new int[Trade_Goods];
        int new_arr_size = 0;
        int temp = 0;
        for (int local1 = 0; local1 < Trade_Goods; local1++)
        {
            bool check = 0;
            file >> buffer;
            for (int local2 = 0; local2 < local1; local2++)
                if (True_arr2[local2] == buffer)
                {
                temp = local1;
                check++;
                break;
                }
            if (check == 0)
            {
                True_arr2[temp] = buffer;
                new_arr_size++;
                temp++;
            }
        }
            int *True_arr3 = new int[new_arr_size];
            for (int local3 = 0; local3 < new_arr_size; local3++)
                True_arr3[local3] = True_arr2[local3];
            qs(True_arr3, 0, new_arr_size - 1);
            delete[]True_arr2;


        vector<vector<int> > Matrix_local = matrix_creator(True_arr3, num, Trade_Goods);
        int limit = Matrix_local.size();
        int count = 0;
        for (int j = 0; j < limit; j++)
        {
            for (int count = 0; count < Great_limit; count++)
                if (Matrix_full[count] == Matrix_local[j])
            {
                Full_Arr[count]++;
                break;
            }
        }
        delete[]True_arr3;
    }
    int max = 0;
    vector <int> Max_number = Matrix_full[0];
    bool check = 0;
    for (int i = 0; i < Great_limit; i++)
    {
        if (Full_Arr[i]>max)
        {
            check = 1;
            max = Full_Arr[i];
            Max_number = Matrix_full[i];
        }
    }
    delete []Full_Arr;
    delete[]True_arr1;
    if (check == 0)
    {
        vector <int> Max_number_fail;
        Max_number_fail.push_back(0);
        return(Max_number_fail);
    }
    return (Max_number);
}

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_pushButton_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Open file"),"E://",".txt (*.txt*)");
    Nametoload = filename;
    ui->label->setText(Nametoload);
}

void MyDialog::on_pushButton_4_clicked()
{
    this->close();
}

void MyDialog::on_pushButton_3_clicked()
{
    QStringList *stringList = new QStringList();
    QStringListModel *listModel = new QStringListModel(*stringList, NULL);
    ui->listView->setModel(listModel);

        int All_Goods;
        int All_Trades;
        ifstream file;
        string string_Nametoload = Nametoload.toStdString();
        file.open(string_Nametoload.c_str(), ios::in);
        char chr = '1';
        if (!file.is_open())
        {
            stringList->append("failed to open the file.");
            listModel->setStringList(*stringList);
            return ;
        }
        while (!file.eof())
        {
            file >> chr;
            if (chr <'0' || chr>'9')
            {
                stringList->append("there are unacceptable symbols in the file.");
                listModel->setStringList(*stringList);
                return;
            }
        }
        file.close();
        file.open(string_Nametoload.c_str(), ios::in);
        file >> All_Goods;
        file >> All_Trades;
        file.close();
        file.open(string_Nametoload.c_str(), ios::in);
        int num = 1;
        for (int i = 1; i <= All_Goods; i++)
        {
        int size = i;
        vector <int> thearr = the_arr(All_Goods, size, All_Trades, string_Nametoload.c_str());
        string str = "";
        stringstream ss;
            ss<<i;
            std::string str1;
            ss>>str1;
        str+="for ";str+=str1;str+=" goods the most popular combination is ";
        for (int j = 0; j < size; j++)
            {
            if (thearr[j] == 0)
            {
               str +="not found";
                break;
            }
            stringstream ss;
                ss<<thearr[j];
                std::string str1;
                ss>>str1;
          str+=(str1)+" ";
            }
        QString qstr = QString::fromStdString(str);
        stringList->append(qstr);
        listModel->setStringList(*stringList);
        //ui->listView->
       // cout << endl;
        }

}


