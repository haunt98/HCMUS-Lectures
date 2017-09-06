from math import sqrt
# su dung cau lenh if
def hoc_luc(diem):
    """Nhap vao diem de xep loai hoc luc"""
    if diem >= 9 and diem <= 10:
        return 'Hoc luc Xuat sac'
    if diem >= 8 and diem < 9:
        return 'Hoc luc Gioi'
    if diem >= 7 and diem < 8:
        return 'Hoc luc Kha'
    if diem >= 6 and diem < 7:
        return 'Hoc luc Trung binh kha'
    if diem >= 5 and diem < 6:
        return 'Hoc luc Trung binh'
    if diem >= 4 and diem < 5:
        return 'Hoc luc yeu'
    else:
        return 'Hoc luc kem'

def nam_nhuan(nam):
    """Kiem tra nam nhuan"""
    if (nam%4 == 0 and nam%100 != 0) or nam%400 == 0:
        return True
    else:
        return False

def so_ngay(thang,nam):
    """Xuat ra so ngay trong thang"""
    if thang == 1 or thang == 3 or thang == 5 or thang == 7 or thang == 8 or thang == 10 or thang == 12:
        return 31
    elif thang == 4 or thang == 6 or thang == 9 or thang == 11:
             return 30

    else:
        if nam_nhuan(nam):
            return 29
        else:
            return 28

def la_tamgiac(a,b,c):
    """Cho biet tam giac gi"""
    if a+b <= c or b+c <= a or c+a <= b:
        return 'Khong phai tam giac'
    else:
        if a == b or b == c or a == b:
            if a == b and b == c:
                return 'Tam giac deu'
            elif a*a+b*b==c*c or b*b+c*c==a*a or c*c+a*a==b*b:
                return 'Tam giac vuong can'
            else:
                return 'Tam giac can'
        elif a*a+b*b==c*c or b*b+c*c==a*a or c*c+a*a==b*b:
            return 'Tam giac vuong'
        else:
            return 'Tam giac thuong'
        
def giai_pt1(a,b):
    """Giai phuong trinh bac nhat ax+b=0"""
    if a == 0:
        if b == 0:
            return 'Vo so nghiem'
        else:
            return 'Vo nghiem'
    else:
        return -b/a

#su dung cau lenh for

def tong_pso(n):
    """Tinh tong 1/1+1/2+1/3+...+1/n"""
    sum = 0
    for i in range(1,n+1):
        sum+=1/i
    return sum

def tong_bp(n):
    """Tinh tong 1^2+2^2+3^2+...+n^2"""
    sum = 0
    for i in range(1,n+1):
        sum+=i*i
    return sum

def lke_uoc(n):
    """Liet ke tat ca cac uoc cua n"""
    for i in range(1,n+1):
        if n%i==0:
            print (i)
    return

def la_nguyento(n):
    """Kiem tra so nguyen to"""
    if n == 1:
        return False
    for i in range(2,round(sqrt(n))+1):
        if n%i == 0:
            return False
    return True

def la_hoanthien(n):
    """Kiem tra so hoan thien"""
    sum = 0
    for i in range(1,n):
        if n%i == 0:
            sum+=i
    if sum == n:
        return True
    return False
