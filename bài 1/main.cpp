#include <iostream>
using namespace std;

class DT
{
private:
    int n;
    double* a;
public:
    DT() //hàm tạo không đối
    {
        this -> n = 0; this -> a = NULL;
    }
    DT(int n1) //hàm tạo 1 đối
    {
        this -> n = n1;
        this -> a = new double[n1 + 1];
    }
    ~DT(){};
    friend ostream& operator << (ostream& os, const DT& d) //hàm toán tử in
    {
        cout << " co dang: ";
        for (int i = d.n; i >= 0; i--)
        {
            
            if (d.a[i] == 1 && i == d.n)
            {
                cout << "x^" << i << " ";
            }else if (d.a[i] == -1 && i == d.n)
            {
                cout << "-x^" << i << " ";
            }else if ((d.a[i] > 0 && i == d.n) || (d.a[i] < 0 && i == d.n))
            {
                if (i == 1)
                {
                    cout <<  d.a[i] << "x ";
                }else
                {
                    cout << d.a[i] << "x^" << i << " ";
                }
            }
            if (d.a[i] > 0 && i < d.n)
            {
                if (d.a[i] == 1)
                {
                    cout << "+ x^" << i << " ";
                }
                if (i == 0)
                {
                    cout << "+ " << d.a[i] << " ";
                }
                if (i == 1)
                {
                    cout << "+ " << d.a[i] << "x ";
                }
                if (i > 1)
                {
                    cout << "+ " << d.a[i] << "x^" << i << " ";
                }
            }
            if (d.a[i] < 0 && i < d.n)
            {
                if (d.a[i] == -1)
                {
                    cout << "- x^" << i << " ";
                }
                if (i == 0)
                {
                    cout << d.a[i] << " ";
                }
                if (i == 1)
                {
                    cout << d.a[i] << "x ";
                }
                if (i > 1)
                {
                    cout << d.a[i] << "x^" << i << " ";
                }
            }
        }
        cout << "\n";
        return os;
    };
    friend istream& operator >> (istream& is, DT& d) //hàm toán tử nhập
    {
        cout << "nhap cac he so cua da thuc: ";
        for (int i = d.n; i >= 0; i--)
        {
            cin >> d.a[i];
        }
        return is;
    };
    DT operator - ()
    {
        DT dtm(n);
        for (int i = n; i >= 0; i--)
        {
            dtm.a[i] = -a[i];
        }
        return dtm;
    }
    DT operator + (const DT& d2) //ham toan tu cong
    {
        DT dtm(0);
        if (n < d2.n)
        {
            dtm.n = d2.n;
            dtm.a[d2.n] = d2.a[d2.n];
            for (int i = d2.n - 1; i >= 0; i--)
            {
                dtm.a[i] = a[i] + d2.a[i];
            }
        }else if (n > d2.n)
        {
            dtm.n = n;
            dtm.a[n] = a[n];
            for (int i = n - 1; i >= 0; i--)
            {
                dtm.a[i] = a[i] + d2.a[i];
            }
        }
        return dtm;
    }
    DT operator - (DT d2) //ham toan tu tru
    {
        DT dtm(0);
        if (n < d2.n)
        {
            dtm.n = d2.n;
            dtm.a[d2.n] = -d2.a[d2.n];
            for (int i = d2.n - 1; i >= 0; i--)
            {
                dtm.a[i] = a[i] - d2.a[i];
            }
        }else if (n > d2.n)
        {
            dtm.n = n;
            dtm.a[n] = a[n];
            for (int i = n - 1; i >= 0; i--)
            {
                dtm.a[i] = a[i] - d2.a[i];
            }
        }
        return dtm;
    }
    DT operator * (const DT& d2) // ham toan tu nhan
    {
        DT dtm(0);
        if ((n > d2.n) || (n <= 1 && d2.n <= 1))
        {
            dtm.n = n + 1;
            int c = (n + 1) * (d2.n + 1);
            int j; int k = n;
            double b[c];
            for (int i = c - 1; i >= 0; i--)
            {
                for (j = n; j > 0; j--)
                {
                    b[i] = a[k] * d2.a[j - d2.n];
                    i--;
                }
                k--;
                i++;
            }
            dtm.a[dtm.n] = b[c-1];
            dtm.a[0] = b[0];
            int l = c - 2;
            for (int i = dtm.n - 1; i > 0; i--)
            {
                dtm.a[i] = b[l] + b[l - 1];
                l = l - 2;
            }
        }
        if ((n < d2.n) || (n <= 1 && d2.n <= 1))
        {
            dtm.n = d2.n + 1;
            int c = (n + 1) * (d2.n + 1);
            int j; int k = d2.n;
            double b[c];
            for (int i = c - 1; i >= 0; i--)
            {
                for (j = d2.n; j > 0; j--)
                {
                    b[i] = d2.a[k] * a[j - n];
                    i--;
                }
                k--;
                i++;
            }
            dtm.a[dtm.n] = b[c-1];
            dtm.a[0] = b[0];
            int l = c - 2;
            for (int i = dtm.n - 1; i > 0; i--)
            {
                dtm.a[i] = b[l] + b[l - 1];
                l = l - 2;
            }
        }
        /*if (n == d2.n)
        {
            dtm.n = n + d2.n;
            int c = (n + 1) * (d2.n + 1);
            int j; int k = n;
            double b[c];
            for (int i = c - 1; i >= 0; i--)
            {
                for (j = n; j >= 0; j--)
                {
                    b[i] = a[k] * d2.a[j];
                    i--;
                }
                k--;
                i++;
            }
            dtm.a[dtm.n] = b[c-1];
            dtm.a[0] = b[0];
            int l = c - 2;
            for (int i = dtm.n - 1; i > 0; i--)
            {
                dtm.a[i] = b[l] + b[l - 1];
                l = l - 2;
            }
        }*/
        return dtm;
    }
    DT copy(DT &d2)
    {
        d2.n = n;
        for (int i = n; i >= 0; i--)
        {
            d2.a[i] = a[i];
        }
        return d2;
    }
    double operator ^(const double& x) //da thuc mu x
    {
        double gt = 0;
        for (int i = n; i >= 0; i--)
        {
            gt = gt + a[i] * pow(x,i);
        }
        return gt;
    }
    double operator[](int i) //truy nhap vao mot he so bat ky cua da thuc
    {
    if (i < 0)
        return double(n);
    else
        return a[i];
    }
    double F (DT p, double x)
    {
        double gt = 0;
        for (int i = p.n; i >= 0; i--)
        {
            gt = gt + p.a[i] * pow(x,i);
        }
        return gt;
    }
};

int main()
{
    cout << "nhap va in ra lan luot cac da thuc p,q,r,s" << endl;
    DT p(2); DT q(1); DT r(0); DT s(1); DT f(100);
    cin >> p; cin >> q; cin >> r; cin >> s;
    cout << "da thuc p" << p; cout << "da thuc q" << q;
    cout << "da thuc r" << r; cout << "da thuc s" << s;
    f = -(p + q) * (r - s);
    cout << "da thuc f" << f;
    cout << "gia tri cua da thuc = " << f.operator^(1) << endl;
    cout << "gia tri cua da thuc = " << f.F(f, 0) << endl;
    cout << "bac / he so cua da thuc: " << f.operator[](-1) << endl;
    return 0;
}

