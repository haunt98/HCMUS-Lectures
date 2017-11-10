#MSSV: 1612180
#Ten: Nguyen Tran Hau
class sv:
    def __init__(self,mssv,ten,gtinh,dtb):
        self.ten=ten
        self.mssv=mssv
        self.gtinh=gtinh
        self.dtb=dtb
        
def doc(f,list): #Bai 28: Doc file
    while True:
        tam = f.readline()
        if not tam:break
        mssv=int(tam)
        ten=' '.join(f.readline().split())
        gtinh=' '.join(f.readline().split())
        dtb=int(f.readline())
        list.append(sv(mssv,ten,gtinh,dtb))
       
def xuat(f,list): #Bai 29: Xuat file
    for i in range(len(list)):
        f.write("MSSV: ")
        f.write(str(list[i].mssv))
        f.write('\n')
        f.write("Ten: ")
        f.write(list[i].ten)
        f.write('\n')
        f.write('Gioi tinh: ')
        f.write(list[i].gtinh)
        f.write('\n')
        f.write("Diem trung binh: ")
        f.write(str(list[i].dtb))
        f.write('\n')

def dtb_max(list): #Bai 3: SV co dtb cao nhat
    max=0
    for i in range(len(list)):
        if list[i].dtb>list[max].dtb:
            max=i
    return list[max].ten
    

def liet(list): #Bai 4: Liet ke sinh vien duoi diem trung binh
    print('Cac sinh vien duoi diem trung binh:')
    for i in range(len(list)):
        if list[i].dtb<5:
            print(list[i].ten)

def tim(mssv,list): #Bai 6: Tim sinh vien khi biet MSSV
    for i in range(len(list)):
        if list[i].mssv==mssv:
            return list[i].ten
            
def them(list): #Bai 9: Them vao mot sinh vien
    mssv=int(input('Nhap MSSV cua Sinh vien moi: '))
    ten=input('Nhap ho va ten cua Sinh vien moi: ')
    gtinh=input('Nhap gioi tinh cua Sinh vien moi: ')
    dtb=int(input('Nhap diem trung binh cua Sinh vien moi: '))
    list.append(sv(mssv,ten,gtinh,dtb))

def xoa(mssv,list): #Bai 10: Xoa mot sinh vien
    for i in range(len(list)):
        if list[i].mssv==mssv:
            del list[i]
            break

def lke_nu(list): #Bai 11: Liet ke sinh vien nu
    print('Danh sach Sinh vien nu:')
    for i in range(len(list)):
        if list[i].gtinh=='nu':
            print(list[i].ten)

def lke_nam(list): #Bai 11: Liet ke sinh vien nam
    print('Danh sach Sinh vien nam:')
    for i in range(len(list)):
        if list[i].gtinh=='nam':
            print(list[i].ten)

def ch_sua(mssv,list): #Bai 13: Tim va chinh sua thong tin SV
    for i in range(len(list)):
        if list[i].mssv==mssv:
            print('Chinh sua thong tin Sinh vien: ',list[i].ten)
            list[i].mssv=int(input('Nhap MSSV moi: '))
            list[i].ten=input('Nhap ho ten moi: ')
            list[i].gtinh=input('Nhap gioi tinh moi: ')
            list[i].dtb=int(input('Nhap diem trung binh moi: '))
            break

list=[]
f_in=open('input.txt','r')
f_out=open('output.txt','w')

doc(f_in,list)

print('Sinh vien co diem trung binh cao nhat:',dtb_max(list))

liet(list)

mssv=int(input('Nhap mssv cua Sinh vien can tim: '))
print('Sinh vien co MSSV',mssv,'la:',tim(mssv,list))

them(list)

mssv=int(input('Nhap mssv cua Sinh vien can xoa: '))
xoa(mssv,list)

lke_nu(list)

lke_nam(list)

mssv=int(input('Nhap MSSV cua Sinh vien can chinh sua: '))
ch_sua(mssv,list)

xuat(f_out,list)

f_in.close()
f_out.close()

        
    

    
    
