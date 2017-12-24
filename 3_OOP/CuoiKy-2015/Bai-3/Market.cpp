#include "Market.h"

void Market::nhap()
{
    int choice;
    do
    {
        cout << "Chon loai sap: 0: thuc pham, 1: quan ao, 2: trang suc: "
             << endl;
        cin >> choice;
        SAP *temp;
        if (choice == 0)
        {
            temp = new SThucPham;
            cin >> *temp;
            ds_sap.push_back(temp);
        }
        else if (choice == 1)
        {
            temp = new SQuanAo;
            cin >> *temp;
            ds_sap.push_back(temp);
        }
        else if (choice == 2)
        {
            temp = new STrangSuc;
            cin >> *temp;
            ds_sap.push_back(temp);
        }
    } while (choice >= 0 && choice <= 2);
}

Market::~Market()
{
    for (size_t i = 0; i < ds_sap.size(); ++i)
    {
        delete ds_sap[i];
    }
    ds_sap.clear();
}

float Market::tongTien()
{
    float sum = 0;
    for (size_t i = 0; i < ds_sap.size(); ++i)
    {
        sum += ds_sap[i]->tienCuoiNam();
    }
    return sum;
}
