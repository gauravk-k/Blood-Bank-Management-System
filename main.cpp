 #include <iostream>
#include <time.h>
#include <math.h>
//#include<conio.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>
#include <string.h>
//#include<winbgim.h>
#include <graphics.h>
#include <dos.h>
#include <iomanip>
using namespace std;
std::fstream data;
// std::fstream index;
// std::fstream locind;
// std::fstream phind;
// std::fstream disind;

char pri[125][15], loc[125][40], dis[125][40], ref1[125][20], ref2[125][20], ref3[125][20], dph[125][20];
int ind[125], count = 0, count1 = 0, count2 = 0, count3 = 0;
char cdate[20], date[20];
void sort1(), sort2(), sort3(), sort4();
int i, j;

int donor_menu = 0;

void graphicB()
{
	int gd = DETECT, gm, midx, midy;
	// initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	char driver[] = "";
	initgraph(&gd, &gm, NULL);

	midx = getmaxx() / 2;
	midy = getmaxy() / 2;

	setcolor(RED);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(midx, midy - 120, "Blood Bank Management");
	outtextxy(midx, midy - 90, "\nPress any key to start");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	setcolor(WHITE);
	//610, 450, 350, 350
	rectangle(630, 450, 320, 350);
	setcolor(GREEN);
	outtextxy(480, 370, "TEAM MEMBERS");
	setcolor(YELLOW);
	outtextxy(480, 390, "ARMAN CHAURASIA       (1RN20IS027)");
	outtextxy(480, 400, "GAURAV KUMAR KASHYAP  (1RN20IS057)");
	getch();
	cleardevice();
	setcolor(RED);
	rectangle(100, 115, 150, 300);
	setfillstyle(SOLID_FILL, RED);
	floodfill(125, 200, RED);
	setcolor(RED);
	rectangle(240, 230, 10, 180);
	setfillstyle(SOLID_FILL, RED);
	floodfill(200, 205, RED);
	floodfill(13, 205, RED);

	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	setcolor(WHITE);
	rectangle(610, 150, 350, 250);

	setcolor(LIGHTGREEN);
	outtextxy(480, 180, "BLOOD DONATION WILL COST YOU");
	outtextxy(480, 190, " NOTHING BUT IT WILL SAVE A LIFE");
	setcolor(LIGHTBLUE);
	outtextxy(480, 210, "Share a little, care a little.");
	outtextxy(480, 220, "-Donate Blood");
	getch();
	closegraph();
}

char *calulateDate(int d, int m, int y, int n)
{
	int pd, pm, py;
	char n_date[20];

	pd = d;
	switch (m)
	{
	case 1:
		py = y - 1;
		switch (n)
		{
		case 1:
			pm = 12;
			break;
		case 2:
			pm = 11;
			break;
		case 3:
			pm = 10;
			break;
		case 4:
			pm = 9;
			break;
		case 5:
			pm = 8;
			break;
		case 6:
			pm = 7;
			break;
		default:
			pm = m;
		}
		break;

	case 2:
		switch (n)
		{
		case 1:
			pm = 1;
			py = y;
			break;
		case 2:
			pm = 12;
			py = y - 1;
			break;
		case 3:
			pm = 11;
			py = y - 1;
			break;
		case 4:
			pm = 10;
			py = y - 1;
			break;
		case 5:
			pm = 9;
			py = y - 1;
			break;
		case 6:
			pm = 8;
			py = y - 1;
			break;
		default:
			pm = m;
			py = y;
		}
		break;

	case 3:
		switch (n)
		{
		case 1:
			pm = 2;
			py = y;
			break;
		case 2:
			pm = 1;
			py = y;
			break;
		case 3:
			pm = 12;
			py = y - 1;
			break;
		case 4:
			pm = 11;
			py = y - 1;
			break;
		case 5:
			pm = 10;
			py = y - 1;
			break;
		case 6:
			pm = 9;
			py = y - 1;
			break;
		default:
			pm = m;
			py = y;
		}
		break;

	case 4:
		switch (n)
		{
		case 1:
			pm = 3;
			py = y;
			break;
		case 2:
			pm = 2;
			py = y;
			break;
		case 3:
			pm = 1;
			py = y;
			break;
		case 4:
			pm = 12;
			py = y - 1;
			break;
		case 5:
			pm = 11;
			py = y - 1;
			break;
		case 6:
			pm = 10;
			py = y - 1;
			break;
		default:
			pm = m;
			py = y;
		}
		break;

	case 5:
		switch (n)
		{
		case 1:
			pm = 4;
			py = y;
			break;
		case 2:
			pm = 3;
			py = y;
			break;
		case 3:
			pm = 2;
			py = y;
			break;
		case 4:
			pm = 1;
			py = y;
			break;
		case 5:
			pm = 12;
			py = y - 1;
			break;
		case 6:
			pm = 11;
			py = y - 1;
			break;
		default:
			pm = m;
			py = y;
		}
		break;

	case 6:
		switch (n)
		{
		case 1:
			pm = 5;
			py = y;
			break;
		case 2:
			pm = 4;
			py = y;
			break;
		case 3:
			pm = 3;
			py = y;
			break;
		case 4:
			pm = 2;
			py = y;
			break;
		case 5:
			pm = 1;
			py = y;
			break;
		case 6:
			pm = 12;
			py = y - 1;
			break;
		default:
			pm = m;
			py = y;
		}
		break;

	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
		py = y;
		pm = m - n;

	default:
		py = y;
		pm = m;
	}
	sprintf(n_date, "%d/%d/%d", pd, pm, py);
	strcpy(cdate, n_date);
	return 0;
}

class Donor
{
private:
	char dname[30], bg[6], gender[6], phone[11], mail[30], drid[10];
	char state[30], district[30], location[30], address[100];
	char date[20];
	int age;

	friend class dREGISTRATION;
};

class dREGISTRATION
{
private:
	Donor d;

public:
	void ins();
	void del();
	void search_donor();
	void BloodBankCenter1();
	void BloodBankCenter2();
	void faq1();
	void faq2();
	void faq3();
	void faq4();
	void LoadIndex();
	void d_update();
	void SearchDistrict(char bg[]);
	void SearchLocation(char bg[]);
	void WriteIndex();
};

void dREGISTRATION::BloodBankCenter1()
{
	/*clrscr();
	char name[100];
	std::ifstream f;
	f.open("center.txt");
	while ((!f.eof()))
	{
		f >> name;
		cout << name << " ";
		f >> name;
		cout << name << " ";
	}
	f.close();
	getchar();
	*/

	//clrscr();
	 cout<< "\nThe list of few Blood Banks in Bangalore, Karnataka"<<endl;

		 cout<<"\n1) Name : Bangalore Baptist Hospital \nPhone : 23330322\nAddress : Bellary Road, Hebbal Bangalore 560024"<<endl;
		 cout<<"\n2) Name : Bangalore Hospital   \nPhone : 26562753\nAddress :  Bangalore"<<endl;
		 cout<<"\n3) Name : Bhagwan Mahaveer Jain Hospital  \nPhone : 22207640\nAddress :  Vasanth Nagar, Bangalore, Karnataka 560052"<<endl;
		 cout<<"\n4) Name : Dr. Shivaji Raos Blood Bank  \nPhone : 22224044\nAddress :  Shanthinagar, Jayanagar, Bangalore, Karnataka 560027"<<endl;
		 cout<<"\n5) Name : Grace Blood Bank  \nPhone : 23336608\nAddress :  Vasanthappa Block, Ganga Nagar, Bangalore- 560032, Karnataka"<<endl;

	 return;
}

void dREGISTRATION::BloodBankCenter2()
{ /*clrscr();
	char name[100];
	std::ifstream f;
	f.open("center1.txt");
	while ((!f.eof()))
	{
		f >> name;
		cout << name << " ";
		f >> name;
		cout << name << " ";
	}
	f.close();
	getchar();
	*/

//		clrscr();
  cout<< "\nThe list of few Blood Banks in Bangalore, Karnataka"<<endl;
	  cout<<"\n6) Name : Karnataka Red Cross Blood Bank (Voluntary)  \nPhone : 22268435\nAddress :  Bangalore"<<endl;
	  cout<<"\n7) Name : Lions Blood Bank (Voluntary)  \nPhone : 22266807\nAddress :  Bangalore"<<endl;
	  cout<<"\n8) Name : Jeeva Voluntary Blood Bank  \nPhone : 26500736\nAddress :  Near-Pavana Enterprises, New Tharagupet, Bangalore, Karnataka 560002"<<endl;
	  cout<<"\n9) Name : Minerva Voluntary Blood Bank  \nPhone : 26574830\nAddress :  V.V. Puram, Basavanagudi, Bangalore - 560004"<<endl;
	  cout<<"\n10) Name : M S Ramaiah Medical Hospital  \nPhone : 23606524\nAddress :  M S Ramaiah Nagar, Msrit Post, Mathikere, Bangalore, Karnataka 560054"<<endl;

  return;
}

void dREGISTRATION::faq1()
{
	int opt;
	// clrscr();
	cout << "\n1.HOW TO DONATE BLOOD?" << endl;
	cout << "\nYou may please visit a Clinical Laboratory center and identify your blood group.";
	cout << "The clinical test will cost you just 50-60. The result shall be provided within 2.";
	cout << "hours time. In case you wish to donate blood now, please visit your nearest.  Blood ";
	cout << "Collection Center. Alternatively you may use the Registration Form given here in the";
	cout << " website and submit for registration.Recipient, relatives or Hospital  authorities will contact you directly." << endl;

	cout << "\n2.ELIGIBILITIES" << endl;
	cout << "\n3.NON-ELIGIBILITIES" << endl;
	cout << "\n4.PREPARATION" << endl;
	cout << "\n5.GO BACK TO MAIN MENU" << endl;

	return;
}

void dREGISTRATION::faq2()
{
	// clrscr();
	cout << "\n1.HOW TO DONATE BLOOD?" << endl;

	cout << "\n2.ELIGIBILITIES" << endl;
	cout << "\n* Any donor,who is healthy,fit and not suffering from any transmittable diseases can donate blood." << endl;
	cout << "* Donor must be 18 -60 years age and having a minimum weight of 50Kg can donate blood" << endl;
	cout << "* Donor Hemoglobin level is 12.5% minimum." << endl;
	cout << "* A donor can again donate blood after 3 months of your last donation of blood." << endl;
	cout << "* BP Diastolic 50 to 100 mm Hg and Systolic 100 to 180 mm Hg." << endl;

	cout << "\n3.NON-ELIGIBILITIES" << endl;
	cout << "\n4.PREPARATION" << endl;
	cout << "\n5.GO BACK TO MAIN MENU" << endl;
	return;
}

void dREGISTRATION::faq3()
{
	// clrscr();
	cout << "\n1.HOW TO DONATE BLOOD?"
		 << "\n";
	cout << "\n2.ELIGIBILITIES" << endl;

	cout << "\n3.NON-ELIGIBILITIES" << endl;
	cout << "\n* Donors should not suffer from Cardiac arrest, hypertension, kidney alignments, epilepsy or diabetics." << endl;
	cout << "* Ladies with bad miscarriage should avoid donating blood for the next 6 months" << endl;
	cout << "* If donor already donated blood or have been treated for malaria within the last three months." << endl;
	cout << "* If donor consumed alcohol within the last 24 hours." << endl;
	cout << "* If you are HIV+." << endl;
	cout << "* If donor had a dental work for next 24 hours and wait for one month if donor  had a major dental procedure." << endl;

	cout << "\n4.PREPARATION" << endl;
	cout << "\n5.GO BACK TO MAIN MENU" << endl;

	return;
}

void dREGISTRATION::faq4()
{
	// clrscr();
	cout << "\n1.HOW TO DONATE BLOOD?" << endl;
	cout << "\n2.ELIGIBILITIES" << endl;
	cout << "\n3.NON-ELIGIBILITIES" << endl;

	cout << "\n4.PREPARATION" << endl;
	cout << "\n* Prepare yourself by having enough fruit juice and water in the night & morning before you donate blood." << endl;
	cout << "* Avoid donating blood in empty stomach. Eat three hours before you donate blood Avoid fatty foods.";
	cout << "Eat food which is rich in iron such as whole grains, eggs, and beef, and spinach, leafy vegetables, orange and citrus." << endl;
	cout << "* Dont consume Alcohol or caffeine beverages before donating blood." << endl;
	cout << "* Avoid donating blood for 6 months if you had any major surgery." << endl;

	cout << "\n5.GO BACK TO MAIN MENU" << endl;

	return;
}

void dREGISTRATION::ins()
{
	dREGISTRATION dr;
	char b[100], offset[10];
	char ch;
	int pos, high = count;

	data.open("donors.txt", ios::out | ios::app);
	data.seekg(0, ios::end);
	pos = data.tellg();

	// fetching date
	time_t t = time(0);
	tm *now = localtime(&t);
	sprintf(date, "%d/%d/%d", now->tm_mday, (now->tm_mon + 1), (now->tm_year + 1900));

	// clrscr();

	cout << "\nEnter Donor phone number : ";
	cin >> d.phone;

	for (int low = 0; low <= high;)
	{
		int mid = (low + high) / 2;
		int k = atoi(dph[mid]), m = atoi(d.phone);
		if (k == m)
		{
			cout << setw(44) << "DUPLICATE RECORD!!!";
			return;
		}
		else if (m < k)
			high = mid - 1;
		else if (m > k)
			low = mid + 1;
	}

	cout << "\nEnter Donor Name : ";
	cin >> d.dname;
	cout << "\nEnter your blood group : ";
	cin >> d.bg;
	cout << "\nEnter your age : ";
	cin >> d.age;
	cout << "\nEnter your gender : ";
	cin >> d.gender;
	cout << "\nEnter your mailid : ";
	cin >> d.mail;
	cout << "\nEnter your state : ";
	cin >> d.state;
	cout << "\nEnter your district : ";
	cin >> d.district;
	cout << "\nEnter your area : ";
	cin >> d.location;
	cout << "\nEnter your address : ";
	cin >> d.address;
	cout << "\nHave you donated blood in past 6 months ? (y/n) : ";
	cin >> ch;

	if (ch == 'y')
	{
		int x, y, u, n;
		cout << "\nHow many months ago you have donated ?" << endl;
		cin >> n;
		sscanf(date, "%d/%d/%d", &x, &y, &u);
		calulateDate(x, y, u, n);
		strcpy(d.date, cdate);
	}
	else
	{
		// sprintf(cdate,"%d/%d/%d",1,1,2017);
		strcpy(d.date, "Potential Donor");
	}
	itoa(count, d.drid, 10);

	sprintf(b, "|%s|%s|%s|%d|%s|%s|%s|%s|%s|%s|%s|%s|#", d.drid, d.dname, d.bg, d.age, d.gender, d.phone, d.mail, d.state, d.district, d.location, d.address, d.date);
	data << b;
	cout << b;
	strcpy(pri[count], d.drid);
	ind[count] = pos;

	strcpy(loc[count1], d.location);
	strcpy(dis[count2], d.district);

	strcpy(ref1[count1], d.drid);
	strcpy(ref2[count2], d.drid);
	strcpy(ref3[count3], d.drid);

	strcpy(dph[count3], d.phone);
	cout << " " << pri[count] << " " << ind[count] << " " << loc[count1] << " " << dis[count2] << " " << ref1[count1] << " " << ref2[count2] << " " << ref3[count3] << " " << dph[count3];
	count++;
	count1++;
	count2++;
	count3++;

	data.close();
	dr.WriteIndex();
}

int bsearch()
{
	int low1 = 0, high1 = count1, p, q;
	unsigned long int k, m;
	char ph[11], comp[10], phonec[11], temp3;
	char b[100];

	cout << "\nEnter Donor phone number : ";
	cin >> ph;

	for (i = 0; i < count3; i++)
	{
		int k = atoi(dph[i]), m = atoi(ph);
		if (k == m)
		{
			for (low1 = 0; low1 <= high1;)
			{
				int mid1 = (low1 + high1) / 2;
				p = atoi(pri[mid1]);
				q = atoi(ref3[i]);
				if (p == q)
				{
					return p;
				}
				else if (q < p)
					high1 = mid1 - 1;
				else if (q > p)
					low1 = mid1 + 1;
			}
		}
	}
	return -1;
}

void dREGISTRATION::del()
{
	dREGISTRATION dr;
	char b[100];
	int p, q, r, s, flag = 0;
	// clrscr();

	data.open("donors.txt", ios::in | ios::out);
	flag = bsearch();
	// cout<<flag<<" ";

	if (flag == -1)
		cout << "\nRecord does not exist ";

	else
	{
		data.seekg(ind[flag], ios::beg);
		data.getline(b, 100, '#');
		b[1] = '*';

		for (i = 0; i < count; i++)
		{
			p = atoi(pri[i]);
			if (p == flag)
				pri[i][0] = '*';

			q = atoi(ref1[i]);
			if (q == flag)
				loc[i][0] = '*';

			r = atoi(ref2[i]);
			if (r == flag)
				dis[i][0] = '*';

			s = atoi(ref3[i]);
			if (s == flag)
			{
				ref3[i][0] = '*';
				dph[i][0] = '*';
			}
		}

		data.seekg(ind[flag], ios::beg);
		data << b;
		cout << "\n\n\t\t\tDonor Record Deleted";
		dr.WriteIndex();
		getchar();
	}

	data.close();
}

int bsearch1()
{
	int low1 = 0, high1 = count1, p, q;
	unsigned long int k, m;
	char ph[11], comp[10], phonec[11], temp3;
	char b[100];

	cout << "\nEnter Donor phone number : ";
	cin >> ph;

	for (i = 0; i < count3; i++)
	{
		int k = atoi(dph[i]), m = atoi(ph);
		if (k == m)
		{
			for (low1 = 0; low1 <= high1;)
			{
				int mid1 = (low1 + high1) / 2;
				p = atoi(pri[mid1]);
				q = atoi(ref3[i]);
				if (p == q)
				{
					return mid1;
				}
				else if (q < p)
					high1 = mid1 - 1;
				else if (q > p)
					low1 = mid1 + 1;
			}
		}
	}
	return -1;
}

void dREGISTRATION::d_update()
{
	dREGISTRATION dr;
	char b[100];
	int p, q, r, flag = 0;
	// clrscr();

	data.open("donors.txt", ios::in | ios::out);
	std::ofstream index;
	index.open("findex.txt", ios::in);
	flag = bsearch1();
	// cout<<flag<<" ";

	if (flag == -1)
	{
		cout << "\n\n\t\t\tRecord does not exist ";
		return;
	}

	data.seekg(ind[flag], ios::beg);
	data.getline(b, 300, '#');

	sscanf(b, "|%[^|]|%[^|]|%[^|]|%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]", d.drid, d.dname, d.bg, &d.age, d.gender, d.phone, d.mail, d.state, d.district, d.location, d.address, d.date);

	cout << "\nDonated blood ? Enter the date when you donated blood (in dd mm yyyy format) : " << endl;
	cin >> p >> q >> r;

	sprintf(d.date, "%d/%d/%d", p, q, r);
	sprintf(b, "|%s|%s|%s|%d|%s|%s|%s|%s|%s|%s|%s|%s|#", d.drid, d.dname, d.bg, d.age, d.gender, d.phone, d.mail, d.state, d.district, d.location, d.address, d.date);
	data.seekg(ind[flag], ios::beg);
	data << b;
	cout << "\n\n\t\t\tDonor Record Updated!!!!";

	data.close();
	index.close();
}

void dREGISTRATION::search_donor()
{
	dREGISTRATION dr;
	int ch;
	char bg[6];
	// clrscr();
	cout << "\nEnter Blood Group you want to search for : ";
	cin >> bg;
	do
	{
		cout << "\n\nSearch by :\n1.District\t2.Area\t3:Go Back\nEnter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			dr.SearchDistrict(bg);
			break;
		case 2:
			dr.SearchLocation(bg);
			break;
		case 3:
			break;
		default:
			cout << "\nPlease enter correct option!!!!!!";
		}
		// clrscr();

	} while (ch != 3);
}

int bsearchloc(char temp[])
{
	int low = 0, high = count, k, m, mid;
	// cout<<temp;
	for (low = 0; low <= high;)
	{
		mid = (low + high) / 2;
		k = atoi(pri[mid]), m = atoi(temp);
		if (k == m)
		{
			return mid;
		}
		else if (m < k)
			high = mid - 1;
		else if (m > k)
			low = mid + 1;
	}

	return -1;
}

void dREGISTRATION::SearchDistrict(char bg[])
{

	dREGISTRATION dr;
	char b[100], name[20], temp[100];
	int pos, flag1 = 0;
	// clrscr();

	data.open("donors.txt", ios::in);
	std::ifstream index;
	index.open("fdist.txt", ios::in);

	cout << "\nEnter district name : ";
	cin >> name;
	while (!index.eof())
	{
		index.getline(b, 100, '#');
		if (index.eof())
			break;
		sscanf(b, "|%[^|]|%[^|]", d.district, temp);
		if (strcmpi(d.district, name) == 0)
		{
			pos = bsearchloc(temp);
			data.seekg(ind[pos], ios::beg);
			data.getline(b, 300, '#');

			sscanf(b, "|%[^|]|%[^|]|%[^|]|%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]", d.drid, d.dname, d.bg, &d.age, d.gender, d.phone, d.mail, d.state, d.district, d.location, d.address, d.date);
			// fflush(stdout);
			if (strcmpi(d.bg, bg) == 0)
			{
				flag1 = 1;
				cout << d.dname << " " << d.bg << " " << d.age << " " << d.gender << " " << d.phone << " " << d.location << " "
					 << "(Last Donated : " << d.date << ")" << endl;
			}
		}
	}
	if (flag1 == 0)
	{
		cout << "\nNo Donors found in " << name << endl;
		getchar();
	}
	cout << "\n";
	index.close();

	getchar();
	data.close();
	return;
}

void dREGISTRATION::SearchLocation(char bg[6])
{

	dREGISTRATION dr;
	char b[100], name[20], temp[100];
	int pos, flag1 = 0;
	// clrscr();

	data.open("donors.txt", ios::in);
	std::ifstream index;
	index.open("floc.txt", ios::in);

	cout << "\nEnter area name : ";
	cin >> name;

	while (!index.eof())
	{
		index.getline(b, 100, '#');
		if (index.eof())
			break;
		sscanf(b, "|%[^|]|%[^|]", d.location, temp);
		if (strcmpi(d.location, name) == 0)
		{
			pos = bsearchloc(temp);
			data.seekg(ind[pos], ios::beg);
			data.getline(b, 300, '#');

			sscanf(b, "|%[^|]|%[^|]|%[^|]|%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]", d.drid, d.dname, d.bg, &d.age, d.gender, d.phone, d.mail, d.state, d.district, d.location, d.address, d.date);
			// fflush(stdout);
			if (strcmpi(d.bg, bg) == 0)
			{
				flag1 = 1;
				cout << d.dname << " " << d.bg << " " << d.age << " " << d.gender << " " << d.phone << " " << d.location << " "
					 << "(Last Donated : " << d.date << ")" << endl;
			}
		}
	}
	if (flag1 == 0)
	{
		cout << "\nNo Donors found in " << name << endl;
	}
	cout << "\n";
	index.close();

	getchar();
	data.close();
	return;
}

void dREGISTRATION::LoadIndex()
{
	char b[100], temp[100];
	count = 0;

	std::ifstream index, locind, disind, phind;
	index.open("findex.txt", ios::in);
	locind.open("floc.txt", ios::in);
	disind.open("fdist.txt", ios::in);
	phind.open("fph.txt", ios::in);

	while (index)
	{
		index.getline(b, 100, '#');
		if (index.eof())
			break;
		sscanf(b, "|%[^|]|%[^|]", pri[count], temp);
		ind[count] = atoi(temp);
		count++;
	}

	count3 = 0;
	while (phind)
	{
		phind.getline(b, 100, '#');
		if (phind.eof())
			break;
		sscanf(b, "|%[^|]|%[^|]", dph[count3], ref3[count3]);
		count3++;
	}

	count1 = 0;
	while (locind)
	{
		locind.getline(b, 100, '#');
		if (locind.eof())
			break;
		sscanf(b, "|%[^|]|%[^|]|%[^|]", loc[count1], ref1[count1]);
		count1++;
	}

	count2 = 0;
	while (disind)
	{
		disind.getline(b, 100, '#');
		if (disind.eof())
			break;
		sscanf(b, "|%[^|]|%[^|]", dis[count2], ref2[count2]);
		count2++;
	}

	index.close();
	locind.close();
	disind.close();
	phind.close();
}

void dREGISTRATION::WriteIndex()
{
	char b[100];
	std::ofstream index, locind, disind, phind;
	index.open("findex.txt");
	locind.open("floc.txt");
	disind.open("fdist.txt");
	phind.open("fph.txt");
	// index.seekg(0,ios::end);
	// locind.seekg(0,ios::end);
	// disind.seekg(0,ios::end);
	// phind.seekg(0,ios::end);

	sort1();
	sort2();
	sort3();
	sort4();

	for (i = 0; i < count; i++)
	{
		itoa(ind[i], b, 10);
		index << "|" << pri[i] << "|" << b << "|"
			  << "#";
	}

	for (i = 0; i < count3; i++)
	{
		phind << "|" << dph[i] << "|" << ref3[i] << "|"
			  << "#";
	}

	for (i = 0; i < count1; i++)
	{
		locind << "|" << loc[i] << "|" << ref1[i] << "|"
			   << "#";
	}

	for (i = 0; i < count2; i++)
	{
		disind << "|" << dis[i] << "|" << ref2[i] << "|"
			   << "#";
	}

	index.close();
	locind.close();
	disind.close();
	phind.close();
}

int main()
{
	graphicB();
	dREGISTRATION dr;
	// clrscr();

	dr.LoadIndex();
	int ch;
	char date[20];
donor_menu:
	while (1)
	{
		cout << "\n"
			 << setw(43) << "MAIN MENU" << endl;
		cout << "\n\t1.Register as Donor\t\t\t2.Unregister as Donor \n\t3.Update Donor Record \t\t\t4.Search Donor\n\t5.Blood Bank Center \t\t\t6.FAQs\n\t7.Exit \n\n\tEnter your choice : ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			dr.ins();
			break;
		case 2:
			dr.del();
			break;
		case 3:
			dr.d_update();
			break;
		case 4:
			dr.search_donor();
			break;
		case 5:
		{
			dr.BloodBankCenter1();
			int z;
			do
			{
				cout << "\n 1.Next\t\t2.Previous\t3.Go back to Main Menu \nEnter your choice : ";
				cin >> z;

				switch (z)
				{
				case 1:
					dr.BloodBankCenter2();
					break;
				case 2:
					dr.BloodBankCenter1();
					break;
				case 3:
					break;
				default:
					cout << "\nIncorrect Option!!!!";
				}
			} while (z != 3);
		}
		break;

		case 6:
		{
			dr.faq1();
			int opt;
			do
			{
				cout << "\nEnter your choice : ";
				cin >> opt;

				switch (opt)
				{
				case 1:
					dr.faq1();
					break;
				case 2:
					dr.faq2();
					break;
				case 3:
					dr.faq3();
					break;
				case 4:
					dr.faq4();
					break;
				case 5:
					break;
				default:
					cout << "\nIncorrect Option!!!!";
				}
			} while (opt != 5);
		}
		break;
		case 8:
		{
			int x, y, u, n;
			char date[20];
			time_t t = time(0);
			tm *now = localtime(&t);
			sprintf(date, "%d/%d/%d", now->tm_mday, (now->tm_mon + 1), (now->tm_year + 1900));
			cout << date << endl;
			cout << "\nHow many months ago you have donated ?" << endl;
			cin >> n;
			sscanf(date, "%d/%d/%d", &x, &y, &u);
			cout << x << " " << y << " " << u << endl;
			calulateDate(x, y, u, n);
			cout << cdate;
		}
		break;
		default: // clrscr();
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t\tTHANK YOU!!!!";
			getchar();
			exit(0);
		}

		getchar();

		// clrscr();
		// int i;
		// cin>>i;
	}
	return 0;
}

void sort1()
{
	char temp[20];
	int tempind, k, l;

	for (i = 0; i < count; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			k = atoi(pri[i]);
			l = atoi(pri[j]);
			if (k > l)
			{
				strcpy(temp, pri[i]);
				strcpy(pri[i], pri[j]);
				strcpy(pri[j], temp);
				tempind = ind[j];
				ind[j] = ind[i];
				ind[i] = tempind;
			}
		}
	}
}

void sort2()
{
	char temp[40], temp1[40];

	for (i = 0; i < count1; i++)
	{
		for (j = i + 1; j < count1; j++)
		{
			if (strcmpi(loc[i], loc[j]) > 0)
			{
				strcpy(temp, loc[i]);
				strcpy(loc[i], loc[j]);
				strcpy(loc[j], temp);
				strcpy(temp1, ref1[i]);
				strcpy(ref1[i], ref1[j]);
				strcpy(ref1[j], temp1);
			}
		}
	}
}

void sort3()
{
	char temp[40], temp1[40];

	for (i = 0; i < count2; i++)
	{
		for (j = i + 1; j < count2; j++)
		{
			if (strcmpi(dis[i], dis[j]) > 0)
			{
				strcpy(temp, dis[i]);
				strcpy(dis[i], dis[j]);
				strcpy(dis[j], temp);
				strcpy(temp1, ref2[i]);
				strcpy(ref2[i], ref2[j]);
				strcpy(ref2[j], temp1);
			}
		}
	}
}

void sort4()
{
	char temp[20], temp1[40];
	int k, l;

	for (i = 0; i < count; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			k = atoi(ref3[i]);
			l = atoi(ref3[j]);
			if (k > l)
			{
				strcpy(temp, ref3[i]);
				strcpy(ref3[i], ref3[j]);
				strcpy(ref3[j], temp);
				strcpy(temp1, dph[i]);
				strcpy(dph[i], dph[j]);
				strcpy(dph[j], temp);
			}
		}
	}
}
