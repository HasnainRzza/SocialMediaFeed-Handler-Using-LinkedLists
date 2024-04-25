#include <windows.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Post
{
public:
    int ID;
    string text;
    time_t TimeStamp;
    Post *next;

    Post(string user_input, int id, int ct) : ID(id), text(user_input), TimeStamp(ct), next(nullptr) {}
};

class Feed
{
private:
    int ids[1000];
    Post *address[1000];
    int index;
    int nposts;
    int sp_chk;
    char stamps[1000];

public:
    Post *head;
    Post *current;
    Feed() : head(nullptr), current(nullptr), nposts(0), index(0)
    {
        for (int i = 0; i < 1000; i++)
        {
            address[i] = nullptr;
        }
    };
    int gettimestamp()
    {
        time_t ct = time(nullptr);
        return static_cast<int>(ct);
    }
    void wait_for_seconds(int s)
    {
        Sleep(s * 1000);
    }
    void Add_Post(string user_input)
    {

        int id = rand() % 9000 + 1000;
        ids[index] = id;
        // Get the current time here

        int ct = gettimestamp();
        wait_for_seconds(1);
        Post *newpost = new Post(user_input, id, ct);
        nposts++;
        address[index] = newpost;
        index++;

        if (head == nullptr || newpost->TimeStamp < head->TimeStamp)
        {
            newpost->next = head;
            head = newpost;
            return;
        }
        else
        {
            current = head;
            while (current->next != nullptr && newpost->TimeStamp > current->TimeStamp)
            {
                current = current->next;
            }
            newpost->next = current->next;
            current->next = newpost;
        }
    }
    int *search_post(string user_input)
    {
        int *temp_ids = new int[100];
        for (int i = 0; i < 100; i++)
        {
            temp_ids[i] = 0;
        }
        int i = 0;
        bool flag = false;
        current = head;
        while (current != nullptr)
        {

            size_t flag = current->text.find(user_input);
            if (flag != string::npos)
            {

                temp_ids[i] = current->ID;
                cout << temp_ids[i] << " ";
                i = i + 1;

                cout << "POST: " << current->text << "  ID:" << current->ID << "\n";
            }
            flag = false;
            current = current->next;
        }

        return temp_ids;
    }
    void sort_feed()
    {
        Post *temp = nullptr;
        bool swapped;
        do
        {
            swapped = false;
            current = head;
            while (current->next != temp)
            {
                if (current->TimeStamp > current->next->TimeStamp)
                {
                    Post *t = current->next;
                    current->next = t->next;
                    t->next = current;
                    if (current == head)
                        head = t;
                    else
                    {
                        Post *prev = head;
                        while (prev->next != current)
                            prev = prev->next;
                        prev->next = t;
                    }
                    swapped = true;
                }
                else
                {
                    current = current->next;
                }
            }
            temp = current;
        } while (swapped);
    }
    string stamp(time_t st)
    {
        struct tm *tim;
        tim=gmtime(&st);
        char buf[80];
        strftime(buf,sizeof(buf),"%Y-%m-%d %H:%M:%S",tim);
        return buf;
    }
    void edit_post(int id, string newtext)
    {
        current = head;
        while (current != nullptr)
        {
            if (current->ID == id)
            {
                current->TimeStamp = gettimestamp();
                current->text = newtext;
                break;
            }
            current = current->next;
        }
    }
    void display()
    {
        current = head;
        cout << "\n-----------------";
        while (current != nullptr)
        {
            cout << current->text << " - " << current->ID << " - " << stamp(current->TimeStamp) << "\n";
            current = current->next;
        }
    }
  
void dec_display()
{
    cout<<"\n-----------------\n";
    for(int i=nposts-1;i>=0;i--)
    {
        cout<<address[i]->text<<" - "<<address[i]->ID<<" - " <<stamp(address[i]->TimeStamp)<<"\n";
    }
}
void delete_a_post(int id)
{   
    current=head;
    Post *temp;
    bool flag=false;
    while(current!=nullptr)
    {
        if(current->next->ID==id&&current->next!=nullptr)
        {
            temp=current->next;
            current->next=current->next->next;
            nposts--;
            flag=true;
            break;
        }
        current=current->next;
    }
    if(!flag)
    {
        cout<<"\nThe ID DOSENT EXISTS\n";
    }
        delete temp;
}

    
};

int main()
{

    Feed list;
    srand(time(nullptr));

    list.Add_Post("Hello World");
    list.Add_Post("How is everyone doing today");
    list.Add_Post("Huuh, finally got some rain");
    list.Add_Post("And this song feels amazing");
    list.Add_Post("still i have got sessionals");
    list.Add_Post("But just enjoy in what you have ALLAH is with YOU ;)");
    list.Add_Post("I should be going, see you guys later.");
    list.Add_Post("Bye");
    int *ids = list.search_post("song");
    // cout<<"\n\nThe list of IDS for the post are: ";
    // for(int i=0;ids[i]!=0;i++)
    // {
    //     cout<<ids[i]<<" ";
    // }
    list.edit_post(ids[0], "hello guys");
    list.sort_feed();
    
    list.display(); // normal display
    int user=0;
    cout<<"enter number: ";
    cin>>user;
    list.delete_a_post(user);
    cout<<"this is display in ascending order:-----\n ";
    list.display(); // oldest display/
        cout<<"this is display in decending order:-----\n ";
    list.dec_display();

    return 0;
}
