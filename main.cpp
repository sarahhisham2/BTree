#include <iostream>
#include <fstream>
using namespace std;


class node
{
public:
    int value;
    int address;
    node()
    {
        value = -1;
        address = -1;
    }
};
class page
{
public:
    node *RecordID = new node[5];
    bool leaf;
    page()
    {
        for(int i=0 ; i < 5 ; i++)
        {
            RecordID[i].address = -1;
            RecordID[i].value = -1;
        }
        leaf = true;
    }
};
void CreateIndexFileFile (string FileName, int NumberOfRecords)
{
    page p;
    fstream file;
	file.open("file.txt" , ios::binary);
	int n = -1 ,c = 1;
	for(int i=0 ; i<=NumberOfRecords ; i++)
    {
        file<<n;
        file<<c;

  //      file.write(int c, sizeof c);
        for(int j=0 ; j <= 5 ; j++)
        {
            file.write((char*) & p, sizeof p);
            //file<<n;
    //        file.write((int) & n, sizeof n);
        }
        file<<"\n";
        c++;
    }
}
/* int InsertNewRecordAtIndex (String FileName, int Key, int Address)
 {

 }
int SearchARecord (string filename, int RecordID)
{

}
void PrintFile(string FileName)
{

}
void PrintUI()
{

}
*/
int main()
{
    cout << "Hello world!" << endl;
    string n;
    int r;
    cin>>n;
    cin>>r;
    CreateIndexFileFile(n,r);
    return 0;
}
