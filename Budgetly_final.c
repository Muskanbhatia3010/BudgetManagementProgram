#include<stdio.h>
#include<string.h>
#include<windows.h>
int spend, coup_ch;
int Budget_entered;
int gspent_yet,mspent_yet,rspent_yet,hspent_yet,tspent_yet;
int total = 0;
int save =0, spend = 0, goal =0;
void SetColor(int ForgC);
void home();
void view_details();
void login();
void sign_up();
void gro();
void mis();
void travel();
void health();
void recreation();
void main_menu();
void new_entry();
void print_exp();
void details();
void points();
void claim_points(int save, int goal);
void print_points();
void coupon();
void admin_login();
void my_coupon(int);
void main_coupon();

//Adds a longer delay
void title_delay()
{
    for(int i=0;i< 1300000000;i++);
}
//Adds a delay for a few seconds
void delay()
{
    for(int i=0;i< 2000000000;i++);
}
//Saves data regarding points like date and the points earned by the user
typedef struct point_details
{
    int points, d, m, y;
}point_details;
//Stores date for each category(groceries, travel, etc.)
struct date
{
    int day,month,year;
};
struct signup
{
    int salary, otp;
    long long int m_no;
    long int pswd[50], r_pswd[50];
    char uname[25], gender[25], country[50], profession[50], name[50], l_name[50], email_id[50];
};
void main()
{
    SetColor(15); //Please go to line 1218
    printf("\n*************\n*");
    SetColor(34);
    printf(" BUDGET.LY ");
    SetColor(15);
    printf("*");
    printf("\n*************\n");
    title_delay();
    home();
}
//Gives the user/admin the option of log in or sign up
void home()
{
    system("cls");
    int select=0;
    printf("***WELCOME***\n\n***Choose an Option***");
    printf("\n1.Login\n2.Sign in\n3.Quit\n\nSelection: ");
    scanf("%d",&select);
    if(select==1)
        login();
    else if(select == 2)
    {
        sign_up();
    }
    else if(select==3)
    {
        system("cls");
        printf("\nThank You for using BUDGET.LY!!\n\nCome Back Soon!\n");
        exit(0);
    }
    else
    {
        printf("\nInvalid Input");
        delay();
        home();
    }
}
//Allows the user to create an account by entering user id, password and other personal details required
void sign_up()
{
    struct signup s;
    int check_otp = 24680, flag, i;
    char ch = 'a';
    system("cls");
    printf("***Sign Up***\n\n");
    printf("\nEnter first name: ");
    scanf("%s", s.name);
    printf("\nEnter last name: ");
    scanf("%s", s.l_name);
    printf("\nEnter desired user name: ");
    scanf("%s", s.uname);
    back: printf("\nEnter desired password: ");
    i=0;
    while(1)
    {
        ch=getch();
        if(ch==13)
            break;
        else if(ch==8)
        {
            if(i!=0)
            {
                printf("\b");
                printf("%c",32);
                printf("\b");
                i--;
                s.pswd[i]='\0';
            }
		else
            continue;
        }
        else
        {
            putchar('*');
            s.pswd[i]=ch;
            i++;
        }
    }
    s.pswd[i]='\0';
    printf("\n\nRe-enter password: ");
    i=0;
    while(1)
    {
        ch=getch();
        if(ch==13)
            break;
        else if(ch==8)
        {
            if(i!=0)
            {
                printf("\b");
                printf("%c",32);
                printf("\b");
                i--;
                s.r_pswd[i]='\0';
            }
		else
            continue;
        }
        else
        {
            putchar('*');
            s.r_pswd[i]=ch;
            i++;
        }
    }
    s.r_pswd[i]='\0';

    printf("\n\nUser ID created!");
    delay();
    system("cls");
    printf("***Personal Details***\n\n");
    printf("\nEnter mail id: ");
    scanf("%s", s.email_id);
    back1: printf("\nEnter the code sent to your mail id: ");
    scanf("%d",&s.otp);
    if(s.otp == check_otp)
    {
        printf("\nMail ID verified.\n");
        delay();
        goto place;
    }
    else
    {
        printf("\nPlease enter the correct code.\n");
        delay();
        goto back1;
    }
    place : printf("\nEnter country: ");
    scanf("%s", s.country);

    next1: printf("\nEnter mobile number: ");
    scanf("%lld", &s.m_no);
    if(s.m_no<=9000000000)
    {
    printf("\nInvalid Input : Too Few characters\n");
    delay();
    goto next1;
    }
    else if(9999999999<s.m_no)
    {
    printf("\nInvalid Input : Too many characters\n");
    delay();
    goto next1;
    }
    else
    {
    printf("\nEnter gender: ");
    scanf("%s", s.gender);
    printf("\nEnter profession: ");
    scanf("%s", s.profession);
    printf("\nEnter salary: ");
    scanf("%d", &s.salary);
    printf("\n\nPersonal details saved successfully.\n\nPlease log in to your account.");
    delay();
    home();
    }
}
//Authenticates the user/admin by checking the user id and password
void login()
{
    system("cls");
    int i,counter=0,flag=0,choice;
    char uid[25],pwd[25],s_uid[][25]={"shaman123"}, a_uid[][25] = {"admin123"};
    char s_pwd[][25]={"1234"}, a_pwd[][25] = {"5678"},ch='a';
    printf("***LOG IN***\n\nEnter the user id : ");
    scanf("%s",uid);
    printf("\nEnter the password : ");
    i=0;
    while(1)
    {
        ch=getch();
        if(ch==13)
            break;
        else if(ch==8)
        {
            if(i!=0)
            {
                printf("\b");
                printf("%c",32);
                printf("\b");
                i--;
                pwd[i]='\0';
            }
		else
            continue;
        }
        else
        {
            putchar('*');
            pwd[i]=ch;
            i++;
        }
    }
    pwd[i]='\0';
    for(i=0;i<=2;i++)
    {
        if((stricmp(uid,s_uid[i]))==0 && (strcmp(pwd,s_pwd[i]))==0)
        {
            flag=1;
            break;
        }
        else if((stricmp(uid,a_uid[i]))==0 && (strcmp(pwd,a_pwd[i]))==0)
        {
            flag =2;
            break;
        }
    }
    if(flag == 1)
    {
        printf("\n\nUser Authenticated");
        printf("\n\nWelcome!!");
        delay();
        main_menu();
    }
    else if(flag == 2)
    {
        printf("\n\nAdmin Authenticated");
        delay();
        admin_login();
    }
    else
    {
        printf("\n\n\n\t**Invalid Input**");
        flag1: printf("\n1.Go back to login\n2.Create a new user id\n\nSelection");
        scanf("%d",&choice);
        if(choice==1)
            login();
        else if(choice==2)
            home();
        else
            printf("\n**Invalid Input**");
            goto flag1;
    }
    getch();
}
//Authenticates admin
void admin_login()
{
    int ch;
    system("cls");
    printf("Welcome Admin!!");
    printf("\n\nEnter 1 to log out: ");
    scanf("%d", &ch);
    if(ch==1)
    {
        home();
    }
    else
    {
        printf("***Invalid Input***\n");
        delay();
        admin_login();
    }
}
//Allows the user to select some action
void main_menu()
{
    system("cls");
    int ch;
    printf("***BUDGETLY***\n\n1.View Profile Details\n2.Enter your Budget details\n3.New Entry\n4.Print expenditure\n5.Points\n6.Coupons\n7.Log Out\n\nSelection: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        view_details();
        break;
    case 2:
        details();
        break;
    case 3:
        new_entry();
        break;
    case 4:
        print_exp();
        break;
    case 5:
        points();
        break;
    case 6:
        main_coupon();
        break;
    case 7:
        home();
        break;
    default:
        printf("***Invalid Input***\n");
        delay();
        main_menu();
    }
}
//Prints the profile details of the user previously stored
void view_details()
{
    int ch;
    system("cls");
    printf("***Profile Details***");
    printf("\n-----------------------------------------------------------------------------\n");
    printf("\nUsername : shaman123");
    printf("\nName : Shaman Gajbha");
    printf("\nEmail ID : shaman@gmail.com");
    printf("\nMobile No : 9123456789");
    printf("\nGender : F");
    printf("\nCountry : India");
    printf("\nProfession : Architect");
    printf("\nSalary : 100000\n");
    printf("\n-----------------------------------------------------------------------------\n");
    printf("\n\nEnter 1 to go to main menu: ");
    scanf("%d",&ch);
    if(ch==1)
        main_menu();
    else
        printf("***Invalid Input***\n");
        delay();
        view_details();

}
//Allows the user to set the budget and goal at the start of every month
void details()
{
    int ch;
    system("cls");
    printf("***Budget Details***\n\nEnter your budget for the month: ");
    scanf("%d", &spend);
    printf("\nEnter the amount of money you want to save: ");
    scanf("%d", &goal);
    Budget_entered=spend;
    if(spend<goal)
    {
        printf("\n\nYour budget does not allow the entered amount of savings.\n\nPlease enter the details again.\n\n");
        delay();
        details();
    }
    enter : printf("\n\nEnter 1 to go back to main menu: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        main_menu();
        break;
    default:
        printf("***Invalid Input***\n");
        delay();
        goto enter;
    }
}
//Displays categories that best represent the expenditure of the user, for the user to choose
void new_entry()
{
    system("cls");
    int ch;
    printf("***New Entry***\n\n***Categories***");
    printf("\n\n1.Groceries\n2.Travel\n3.Health\n4.Recreation\n5.Miscellaneous\n6.Main menu\n\nSelection: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        gro();
        break;
    case 2:
        travel();
        break;
    case 3:
        health();
        break;
    case 4:
        recreation();
        break;
    case 5:
        mis();
        break;
    case 6:
        main_menu();
        break;
    }
}
//All the following functions will take input of the daily expenditure with date from the user and store it in respective files
//Groceries
void gro()
{
    system("cls");
    FILE *ptr;
    int entry,day,num,ch;
    char bon[999];
    char temp[]="/";
    struct date groc;
    date: printf("***Groceries***\n\nEnter the date(dd/mm/yy): ");
    scanf("%d/%d/%d",&groc.day,&groc.month,&groc.year);
    if(groc.day>31)
    {
        printf("\nPlease enter the correct date.\n\n");
        goto date;
    }
    if(groc.month!=5)
    {
        printf("\nPlease enter the correct month.\n\n");
        goto date;
    }
    printf("\nEnter the amount: ");
    scanf("%d",&entry);
    if(spend==Budget_entered)
        gspent_yet=entry;
    else
        gspent_yet=gspent_yet+entry;
    spend=spend-entry;
    ptr=fopen("groc.txt","a");
    fprintf(ptr,"\n%d/%d/%d\t\t%d\t\t%d /",groc.day,groc.month,groc.year,entry,spend);
    fclose(ptr);
    printf("\nEntry Successful!\n");
    if(spend<0)
    {
        printf("\n\nBudget Exhausted.\n\n");
    }
    printf("\nCurrent budget balance: %d\n",spend);
    ptr = fopen("groc.txt","r");
    menu: printf("\n1.Check Previous Entries\n2.Another entry in groceries\n3.Change Category\n4.Main Menu\n\nSelection: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
    {
        system("cls");
        printf("\n");
        if (ptr)
        {
            while(!feof(ptr))
            {
                fscanf(ptr, "%s",bon);
                num=strcmp(temp,bon);
                if(num==0)
                    printf("\n");
                else
                    printf("%s\t\t",bon);
            }
        }
        printf("\n\nBudget balance: %d", spend);
        printf("\n\nEnter 1 to go back:");
        scanf("%d",&ch);
        if(ch==1)
        {
            system("cls");
            goto menu;
            break;
        }
        printf("\n");
        break;
    }
    case 2:
        gro();
        break;
    case 3:
        new_entry();
        break;
    case 4:
        main_menu();
        break;
    default:
        printf("***Invalid Input***\n");
        delay();
        goto menu;
   }
}
//Travel
void travel()
{
    system("cls");
    FILE *t_ptr;
    int entry,day,num,ch;
    char bon[999];
    char temp[]="/";
    struct date trav;
    date: printf("***Travel***\n\nEnter the date(dd/mm/yy): ");
    scanf("%d/%d/%d",&trav.day,&trav.month,&trav.year);
    if(trav.day>31)
    {
        printf("\nPlease enter the correct date.\n\n");
        goto date;
    }
    if(trav.month!=5)
    {
        printf("\nPlease enter the correct month.\n\n");
        goto date;
    }
    printf("\nEnter the amount: ");
    scanf("%d",&entry);
    if(spend==Budget_entered)
        tspent_yet=entry;
    else
        tspent_yet=tspent_yet+entry;
    spend=spend-entry;
    t_ptr=fopen("travel.txt","a");
    fprintf(t_ptr,"\n%d/%d/%d\t\t%d\t\t%d /",trav.day,trav.month,trav.year,entry,spend);
    fclose(t_ptr);
    //system("cls");
    printf("\nEntry Successful!\n");
    if(spend<0)
    {
        printf("\n\nBudget Exhausted.\n\n");
    }
    printf("\nCurrent budget balance: %d\n",spend);
    t_ptr = fopen("travel.txt","r");
    printf("\n");
    menu: printf("\n1.Check Previous Entries\n2.Another entry in Travel\n3.Change Category\n4.Main Menu\n\nSelection: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        {
            system("cls");
            printf("\n");
            if (t_ptr)
            {
                while(!feof(t_ptr))
                {
                    fscanf(t_ptr, "%s",bon);
                    num=strcmp(temp,bon);
                    if(num==0)
                        printf("\n");
                    else
                        printf("%s\t\t",bon);
                }
            }
            printf("\n\nBudget balance: %d", spend);
            printf("\n\nEnter 1 to go back:");
            scanf("%d",&ch);
            if(ch==1)
            {
                system("cls");
                goto menu;
                break;
            }
            printf("\n");
            break;
        }
    case 2:
        travel();
        break;
    case 3:
        new_entry();
        break;
    case 4:
        main_menu();
        break;
    default:
        printf("***Invalid Input***\n");
        delay();
        goto menu;
   }
}
//Health
void health()
{
    system("cls");
    FILE *h_ptr;
    int entry,day,num,ch;
    char bon[999];
    char temp[]="/";
    struct date heal;
    date: printf("***Health***\n\nEnter the date(dd/mm/yy): ");
    scanf("%d/%d/%d",&heal.day,&heal.month,&heal.year);
    if(heal.day>31)
    {
        printf("\nPlease enter the correct date.\n\n");
        goto date;
    }
    if(heal.month!=5)
    {
        printf("\nPlease enter the correct month.\n\n");
        goto date;
    }
    printf("\nEnter the amount: ");
    scanf("%d",&entry);
    if(spend==Budget_entered)
        hspent_yet=entry;
    else
        hspent_yet=hspent_yet+entry;
    spend=spend-entry;
    h_ptr=fopen("health.txt","a");
    fprintf(h_ptr,"\n%d/%d/%d\t\t%d\t\t%d /",heal.day,heal.month,heal.year,entry,spend);
    fclose(h_ptr);
    printf("\nEntry Successful!\n");
    if(spend<0)
    {
        printf("\n\nBudget Exhausted.\n\n");
    }
    printf("\nCurrent budget balance: %d\n",spend);
    h_ptr = fopen("health.txt","r");
    menu: printf("\n1.Check Previous Entries\n2.Another entry in Health\n3.Change Category\n4.Main Menu\n\nSelection: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        {
            system("cls");
            printf("\n");
            if(h_ptr)
            {
                while(!feof(h_ptr))
                {
                    fscanf(h_ptr, "%s",bon);
                    num=strcmp(temp,bon);
                    if(num==0)
                        printf("\n");
                    else
                        printf("%s\t\t",bon);
                }
            }
            printf("\n\nBudget balance: %d", spend);
            printf("\n\nEnter 1 to go back:");
            scanf("%d",&ch);
            if(ch==1)
            {
                system("cls");
                goto menu;
                break;
            }
            printf("\n");
            break;
        }

    case 2:
        health();
        break;
    case 3:
        new_entry();
        break;
    case 4:
        main_menu();
        break;
    default:
        printf("***Invalid Input***\n");
        delay();
        goto menu;
   }
}
//Recreation
void recreation()
{
    system("cls");
    FILE *r_ptr;
    int entry,day,num,ch;
    char bon[999];
    char temp[]="/";
    struct date recr;
    date: printf("***Recreation***\n\nEnter the date(dd/mm/yy): ");
    scanf("%d/%d/%d",&recr.day,&recr.month,&recr.year);
    if(recr.day>31)
    {
        printf("\nPlease enter the correct date.\n\n");
        goto date;
    }
    if(recr.month!=5)
    {
        printf("\nPlease enter the correct month.\n\n");
        goto date;
    }
    printf("\nEnter the amount: ");
    scanf("%d",&entry);
    if(spend==Budget_entered)
        rspent_yet=entry;
    else
        rspent_yet=rspent_yet+entry;
    spend=spend-entry;
    r_ptr=fopen("recreation.txt","a");
    fprintf(r_ptr,"\n%d/%d/%d\t\t%d\t\t%d /",recr.day,recr.month,recr.year,entry,spend);
    fclose(r_ptr);
    printf("\nEntry Successful!\n");
    if(spend<0)
    {
        printf("\n\nBudget Exhausted.\n\n");
    }
    printf("\nCurrent budget balance: %d\n",spend);
    r_ptr = fopen("recreation.txt","r");
    menu:printf("\n1.Check Previous Entries\n2.Another entry in Recreation\n3.Change Category\n4.Main Menu\n\nSelection: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        {
            system("cls");
            printf("\n");
            if (r_ptr)
            {
                while(!feof(r_ptr))
                {
                    fscanf(r_ptr, "%s",bon);
                    num=strcmp(temp,bon);
                    if(num==0)
                        printf("\n");
                    else
                        printf("%s\t\t",bon);
                }
            }
            printf("\n\nBudget balance: %d", spend);
            printf("\n\nEnter 1 to go back:");
            scanf("%d",&ch);
            if(ch==1)
            {
                system("cls");
                goto menu;
                break;
            }
            printf("\n");
            break;
        }
    case 2:
        recreation();
        break;
    case 3:
        new_entry();
        break;
    case 4:
        main_menu();
        break;
    default:
        printf("***Invalid Input***\n");
        delay();
        goto menu;
   }
}
//Miscellaneous
void mis()
{
    system("cls");
    FILE *m_ptr;
    int entry,day,num,ch;
    char bon[999];
    char temp[]="/";
    struct date misc;
    date: printf("***Miscellaneous***\n\nEnter the date(dd/mm/yy): ");
    scanf("%d/%d/%d",&misc.day,&misc.month,&misc.year);
    if(misc.day>31)
    {
        printf("\nPlease enter the correct date.\n\n");
        goto date;
    }
    if(misc.month!=5)
    {
        printf("\nPlease enter the correct month.\n\n");
        goto date;
    }
    printf("\nEnter the amount: ");
    scanf("%d",&entry);
    if(spend==Budget_entered)
        mspent_yet=entry;
    else
        mspent_yet=mspent_yet+entry;
    spend=spend-entry;
    m_ptr=fopen("misc.txt","a");
    fprintf(m_ptr,"\n%d/%d/%d\t\t%d\t\t%d /",misc.day,misc.month,misc.year,entry,spend);
    fclose(m_ptr);
    printf("\nEntry Successful!\n");
    if(spend<0)
    {
        printf("\n\nBudget Exhausted.\n\n");
    }
    printf("\nCurrent budget balance: %d\n",spend);
    m_ptr = fopen("misc.txt","r");
    printf("\n");
    menu:printf("\n1.Check Previous Entries\n2.Another entry in miscellaneous\n3.Change Category\n4.Main Menu\n\nSelection: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        {
            system("cls");
            printf("\n");
            if (m_ptr)
            {
                while(!feof(m_ptr))
                {
                    fscanf(m_ptr, "%s",bon);
                    num=strcmp(temp,bon);
                    if(num==0)
                        printf("\n");

                    else
                        printf("%s\t\t",bon);
                }
            }
            printf("\n\nBudget balance: %d", spend);
            printf("\n\nEnter 1 to go back: ");
            scanf("%d",&ch);
            if(ch==1)
            {
                system("cls");
                goto menu;
                break;
            }
            printf("\n");
            break;
        }
    case 2:
        mis();
        break;
    case 3:
        new_entry();
        break;
    case 4:
        main_menu();
        break;
    default:
        printf("***Invalid Input***\n");
        delay();
        goto menu;
   }

}
//This allows the user to view all the previous entries category-wise and all together
void print_exp()
{
    system("cls");
    int ch, num, ch1, total_spent;
    FILE *ptr,*m_ptr,*r_ptr,*t_ptr,*h_ptr;
    char bon[999];
    char temp[]="/";
    total_spent = Budget_entered - spend;
    printf("***Expenditure***\n\nYour Budget Balance for May is : %d\n\nTotal amount spent in May: %d\n",spend,total_spent);
    printf("\n");
    printf("\nView expenditure in: \n1.Groceries\n2.Travel\n3.Health\n4.Recreation\n5.Miscellaneous\n6.Total Expenditure\n7.Main Menu\n\nSelection: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        {
            system("cls");
            ptr = fopen("groc.txt","r");
            if (ptr)
            {
                while(!feof(ptr))
                {
                    fscanf(ptr, "%s",bon);
                    num=strcmp(temp,bon);
                    if(num==0)
                        printf("\n");
                    else
                        printf("%s\t\t",bon);
                }
            }
            printf("\n\n\nTotal Expenditure in this category : %d", gspent_yet);
            printf("\n");
            printf("\n\nEnter 1 to go back: ");
            scanf("%d", &ch1);
            if(ch1==1)
            {
                print_exp();
            }
            break;
        }
    case 2:
        {
            system("cls");
            t_ptr = fopen("travel.txt","r");
            if (t_ptr)
            {
                while(!feof(t_ptr))
                {
                    fscanf(t_ptr, "%s",bon);
                    num=strcmp(temp,bon);
                    if(num==0)
                        printf("\n");
                    else
                        printf("%s\t\t",bon);
                }
            }
            //printf("\n");
            printf("\n\n\nTotal Expenditure in this category : %d", tspent_yet);
            printf("\n");
            printf("\n\nEnter 1 to go back: ");
            scanf("%d", &ch1);
            if(ch1==1)
            {
                print_exp();
            }
            break;
        }
    case 3:
        {
            system("cls");
            h_ptr = fopen("health.txt","r");
            if (h_ptr)
            {
                while(!feof(h_ptr))
                {
                    fscanf(h_ptr, "%s",bon);
                    num=strcmp(temp,bon);
                    if(num==0)
                        printf("\n");
                    else
                        printf("%s\t\t",bon);
                }
            }
            printf("\n\n\nTotal Expenditure in this category : %d", hspent_yet);
            printf("\n");
            printf("\n\nEnter 1 to go back: ");
            scanf("%d", &ch1);
            if(ch1==1)
            {
                print_exp();
            }
            break;
        }
    case 4:
        {
            system("cls");
            r_ptr = fopen("recreation.txt","r");
            if (r_ptr)
            {
                while(!feof(r_ptr))
                {
                    fscanf(r_ptr, "%s",bon);
                    num=strcmp(temp,bon);
                    if(num==0)
                        printf("\n");
                    else
                        printf("%s\t\t",bon);
                }
            }
            //printf("\n");
            printf("\n\n\nTotal Expenditure in this category : %d", rspent_yet);
            printf("\n");
            printf("\n\nEnter 1 to go back: ");
            scanf("%d", &ch1);
            if(ch1==1)
            {
                print_exp();
            }
            break;
        }
    case 5:
        {
            system("cls");
            m_ptr = fopen("misc.txt","r");
            if (m_ptr)
            {
                while(!feof(m_ptr))
                {
                    fscanf(m_ptr, "%s",bon);
                    num=strcmp(temp,bon);
                    if(num==0)
                        printf("\n");
                    else
                        printf("%s\t\t",bon);
                }
            }
            //printf("\n");
            printf("\n\n\nTotal Expenditure in this category : %d", mspent_yet);
            //printf("\n");
            printf("\n\nEnter 1 to go back: ");
            scanf("%d", &ch1);
            if(ch1==1)
            {
                print_exp();
            }
            break;
        }
    case 6:
        {
            system("cls");
            printf("------------------------------------------------------------------------------------------------------\n");

            //GROCERIES
            ptr = fopen("groc.txt","r");
            if (ptr)
            {
                while(!feof(ptr))
                {
                    fscanf(ptr, "%s",bon);
                    num=strcmp(temp,bon);
                    if(num==0)
                        printf("\n");
                    else
                        printf("%s\t\t",bon);
                }
            }
            //printf("\n");
            printf("\n\nTotal Expenditure in this category : %d\n\n", gspent_yet);
            printf("\n------------------------------------------------------------------------------------------------------\n");
            //TRAVEL
            t_ptr = fopen("travel.txt","r");
            if (t_ptr)
            {
                while(!feof(t_ptr))
                {
                    fscanf(t_ptr, "%s",bon);
                    num=strcmp(temp,bon);
                    if(num==0)
                        printf("\n");

                    else
                        printf("%s\t\t",bon);
                }
            }
            //printf("\n");
            printf("\n\nTotal Expenditure in this category : %d\n\n", tspent_yet);
            printf("\n------------------------------------------------------------------------------------------------------\n");
            //HEALTH
            h_ptr = fopen("health.txt","r");
            if (h_ptr)
            {
                while(!feof(h_ptr))
                {
                    fscanf(h_ptr, "%s",bon);
                    num=strcmp(temp,bon);
                    if(num==0)
                        printf("\n");

                    else
                        printf("%s\t\t",bon);
                }
            }
            //printf("\n");
            printf("\n\nTotal Expenditure in this category : %d\n\n", hspent_yet);
            printf("\n------------------------------------------------------------------------------------------------------\n");
            //RECREATION
            r_ptr = fopen("recreation.txt","r");
            if (r_ptr)
            {
                while(!feof(r_ptr))
                {
                    fscanf(r_ptr, "%s",bon);
                    num=strcmp(temp,bon);
                    if(num==0)
                        printf("\n");

                    else
                        printf("%s\t\t",bon);
                }
            }
            //printf("\n");
            printf("\n\nTotal Expenditure in this category : %d\n\n", rspent_yet);
            printf("\n------------------------------------------------------------------------------------------------------\n");
            //MISCELLANEOUS
            m_ptr = fopen("misc.txt","r");
            if (m_ptr)
            {
                while(!feof(m_ptr))
                {
                    fscanf(m_ptr, "%s",bon);
                    num=strcmp(temp,bon);
                    if(num==0)
                        printf("\n");

                    else
                        printf("%s\t\t",bon);
                }
            }
            printf("\n\nTotal Expenditure in this category : %d\n\n", mspent_yet);
            printf("\n------------------------------------------------------------------------------------------------------\n");
            printf("\n\n");
            printf("\n\n***Your Budget Balance for May: %d***\n\n***Total amount spent in May: %d***\n",spend,total_spent);
            printf("\nEnter 1 to go back : ");
            scanf("%d", &ch1);
            if(ch1==1)
            {
                print_exp();
            }
           break;
        }
    case 7:
        main_menu();
        break;
    default:
        printf("***Invalid Input***\n");
        delay();
        print_exp();
    }
}
//Allows the user to choose an action to perform regarding points
void points()
{
    int ch;
    system("cls");
    printf("***Points***\n\n1.My Points\n2.Claim points for this month\n3.Claim Coupons\n4.Main menu\n\nSelection: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        print_points(total);
        break;
    case 2:
        claim_points(spend,goal);
        break;
    case 3:
        coupon();
        break;
    case 4:
        main_menu();
        break;
    default:
        printf("***Invalid Input***\n");
        delay();
        points();
    }
}
//Prints the total points earned by user in previous months and newly claimed
void print_points(int total)
{
    system("cls");
    int ch = 0;
    point_details pt;
    printf("***Points***\n\nTotal Points: %d", total);
    printf("\n\n1.Go back\n2.Main menu\n\nSelection: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        points();
        break;
    case 2:
        main_menu();
        break;
    default:
        printf("***Invalid Input***\n");
        delay();
        print_points(total);
    }
    getch();
}
//Allows the user to claim points depending on their savings and goal
void claim_points(int save, int goal)
{
    int rem,temp, ch, points_ach,points_extra;
    system("cls");
    point_details pt;
    pt.points = 0;
    printf("***Claim Points***\n\nEnter todays date: ");
    scanf("%d/%d/%d", &pt.d, &pt.m, &pt.y);
    if(pt.d!=31)
    {
        printf("\n\nYou can claim the points at the end of this month.");
    }
    else if(pt.d==31)
    {
        printf("\n\nYour goal for May: %d\n\nYour savings for May: %d\n",goal, save);
        if(goal == save)
        {
            printf("\n\n100 points claimed for achieving your goal!");
            pt.points += 100;
        }
        else if(save>goal)
        {
            printf("\n\n100 points claimed for achieving your goal!");
            points_ach=100;;
            rem=(save-goal)/100;
            points_extra =(2*rem);

            printf("\n\nExtra %d points for exceeding your goal by %d!", points_extra,(save-goal));
            pt.points = points_ach+points_extra;

            printf("\n\n***%d points earned***", pt.points);

        }
        else if(goal>save)
        {
            if(save>0)
            {
                printf("\n\nZero points earned.\n\nFinal budget balance: %d", save);
            }
            else if(save<0)
            {
                    temp = (-1)*save;
                    printf("\n\nZero points earned\n\nYou went over your budget by: %d", temp);
            }

            menu: printf("\n\n1.Set your goal for next month\n2.Main menu\n\nSelection: ");
            scanf("%d", &ch);
            switch(ch)
            {
            case 1:
                details();
                break;
            case 2:
                main_menu();
                break;
            default:
                printf("***Invalid Input***\n");
                delay();
                goto menu;
            }
        }
        total += pt.points;
    }
    menu1: printf("\n\n1.Go back\n2.Print Points\n3.Main menu\n\nSelection: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        points();
        break;
    case 3:
        main_menu();
        break;
    case 2:
        print_points(total);
        break;
    default:
        printf("***Invalid Input***\n");
        delay();
        goto menu1;

    }
}
//Allows the user to select an action regarding coupons
void main_coupon()
{
    int ch;
    system("cls");
    printf("***Coupons***\n\n1.Claim Coupon\n2.My Coupons\n3.Main menu\n\nSelection: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        coupon();
        break;
    case 2:
        my_coupon(coup_ch);
        break;
    case 3:
        main_menu();
        break;
    default:
        printf("***Invalid Input***\n");
        delay();
        main_coupon();
    }
}
//Allows the user to view and claim(depending on points owned) the coupons at the end of every month offered by Budgetly
void coupon()
{
    int ch;
    system("cls");
    printf("***Coupons***\n\nPoints available: %d", total);
    restart: printf("\n\n  Coupon Code:\t\tPoints Used:\tWebsite:\tDiscount:\t\tCondition:\t\t   Use By:");
    printf("\n");
    printf("\n1.AMAZ10\t\t50\t\tamazon.com\t10 percent\t on orders up to Rs.1000\t   30/06/2021\n\n");
    printf("\n");
    printf("\n2.AMAZ15\t\t100\t\tamazon.com\t15 percent\t on orders up to Rs.1000\t   30/06/2021\n\n");
    printf("\n");
    printf("\n3.AMAZ50\t\t150\t\tamazon.com\t50 percent\t on orders up to Rs.1000\t   30/06/2021\n\n");
    menu: printf("\n\nEnter your choice: ");
    scanf("%d",&coup_ch);
    switch(coup_ch)
    {
    case 1:
        if(total<50)
        {
            coup_ch=0;
            system("cls");
            printf("\nNot enough points!\n");
            printf("\nPoints Balance : %d\n",total);
            delay();
            main_coupon();
            break;
        }
        else
            total = total - 50;
            break;
        break;
    case 2:
        if(total<100)
        {
            coup_ch=0;
            system("cls");
            printf("\nNot enough points!\n");
            printf("\nPoints Balance : %d\n",total);
            delay();
            main_coupon();
            break;
        }
        else
            total -= 100;
            break;
        break;
    case 3:
        if(total<150)
        {
            coup_ch=0;
            system("cls");
            printf("\nNot enough points!\n");
            printf("\nPoints Balance : %d\n",total);
            delay();
            main_coupon();
            break;
        }
        else
            total -= 150;
            break;
        break;
    default:
        printf("***Invalid Input***\n");
        delay();
        goto menu;
    }
    printf("\n\nCoupons claimed successfully!!\nPoints balance: %d",total);
    menu1: printf("\n\nEnter 1 to go back: ");
    scanf("%d", &ch);
    if(ch==1)
    {
        main_coupon();
    }
    else
    {
        printf("***Invalid Input***\n");
        delay();
        goto menu1;
    }
}
//Allows the user to view the coupons availed
void my_coupon(int coup_ch)
{
    int ch;
    system("cls");
    printf("***My Coupons***");
    switch(coup_ch)
    {
    case 1:
        printf("\n\nCoupon Code: AMAZ10\n\nGet 10 percent off on amazon.com on orders up to Rs.1000.\nUse before 30/06/2021\n\n");
        break;
    case 2:
        printf("\n\nCoupon Code: AMAZ15\n\nGet 15 percent off on amazon.com on orders up to Rs.1000.\nUse before 30/06/2021\n\n");
        break;
    case 3:
        printf("\n\nCoupon Code: AMAZ50\n\nGet 50 percent off on amazon.com on orders up to Rs.1000.\nUse before 30/06/2021\n\n");
        break;
    default:
        printf("\n\nNo coupons yet.");
        break;
    }
    menu: printf("\nEnter 1 to go back: ");
    scanf("%d",&ch);
    if(ch==1)
        main_coupon();
    else
    {
        printf("***Invalid Input***\n");
        delay();
        goto menu;
    }

}
//Function that enables the coder to change colors throughout the code
void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

