NAME :  Prathamesh Amrutkat 
Roll no :I3103
Assignment 01

Write a program to implement an address book with options given
below: a) Create address
book. b) View address book. c) Insert a record. d) Delete a record. e)
Modify a record. f) Exit


prathamesh@linux:~$ sh
$ fileExists(){
    if [ ! -e Address_Book.txt ];
    then 
        
        return 1
    fi
}

createAddressBook(){
    if [ ! -e Address_Book.txt ];
    then 
        touch Address_Book.txt 
    fi
    echo "| Name | Email | Phone Number | Address |" > Address_Book.txt
}

viewAddressBook(){
    if [ ! -e Address_Book.txt ];
    then 
        echo "Address Book is Not Created. First Create Address Book"
        return
    fi

    if [ -s Address_Book.txt ];
    then
        cat Address_Book.txt
    else
        echo "Address Book is Empty"
    fi
}

insertRecord(){
    if [ ! -e Address_Book.txt ];
    then 
        echo "Address Book is Not Created. First Create Address Book"
        return
    fi

    read -p "Enter Name: " name
    read -p "Enter Email: " email
    read -p "Enter Phone Number: " phone
    read -p "Enter Address: " address

    
    echo "| $name | $email | $phone | $address |" >> Address_Book.txt

}

deleteRecord(){
    if [ ! -e Address_Book.txt ];
    then 
        echo "Address Book is Not Created. First Create Address Book"
        return
    > fi

    read -p "Enter Name: " name
    if [ -z "$(grep -i $name Address_Book.txt)" ];
    then
        echo "Record Not Found"
    else
        sed>  -i "/$name/d" Address_Book.txt
    fi
}

searchRecord(){
    if [ ! -e Address_Book.txt ];
    then 
>         echo "Address Book is Not Created. First Create Address Book"
>         return
    fi

    read -p "Enter Name: " name
    if [ -z "$(grep -i $name Address> _Book.txt)" ];
    then
        echo "Record Not Found"
    else
        gr> ep -i $name Address_Book.txt
    fi
}

updateRecord(){
    if [ ! -e Address_Book.txt ];
    then 
        echo "Address Book is Not Created. First Create Address Book"
        return
    fi

    read -p "Enter Name: " name

    if [ -z "$(grep$  -i $name Address_Book.txt)" ];
    then
        echo "Record Not Found"
        return
$     fi

    sed -i "/$name/d" Address_Book.txt
    read -p "Enter Email: " email
    read -p "Enter Phone Number: " phone
>     read -p "Enter Address: " address
    echo "| $name | $email | $phone | $address |" >> Address_Book.txt
> }

main(){
    while true;
    do
        echo -e "\nWelcome to Address Book\n"
       >  echo "1. Create Address Book"
        echo "2. View Address Book"
        echo "3. Insert Record"
>         echo "4. Delete Record"
        echo "5. Search Record"
        echo "6. Upda> te Record"
        echo -e "7. Exit\n"

        read -p "Enter Choice: " choice

        case $choice in
            1)
    >         createAddressBook
            ;;
            2)
            viewAddressBook
            ;;
            3)
            insertRecord
            ;;
$             4)
            deleteRecord
            ;;
            5)
   $          searchRecord
            ;;
            6)
            updateRecord
            ;;
    >         7)
            exit
            ;;
            *)
            echo "Invalid Choice"
        >     ;;
        esac
    done
}

main> > > > > > > > > > > $ $ > > > > > > > > > > > > > > > $ $ > > > > > > > > > > > > > > $ $ > > > > > > > > > > > > > > $ $ > > > > > > > > > > > > > > > > > > > > $ $ > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > $ $ 

Welcome to Address Book

1. Create Address Book
2. View Address Book
3. Insert Record
4. Delete Record
5. Search Record
6. Update Record
7. Exit

Enter Choice: 1
 
Welcome to Address Book

1. Create Address Book
2. View Address Book
3. Insert Record
4. Delete Record
5. Search Record
6. Update Record
7. Exit

Enter Choice: 2
| Name | Email | Phone Number | Address |
 
Welcome to Address Book

1. Create Address Book
2. View Address Book
3. Insert Record
4. Delete Record
5. Search Record
6. Update Record
7. Exit

Enter Choice: 3
Enter Name: JAY
Enter Email: jay@gmail.com         
Enter Phone Number: 9172553121
Enter Address: Pune
 
Welcome to Address Book

1. Create Address Book
2. View Address Book
3. Insert Record
4. Delete Record
5. Search Record
6. Update Record
7. Exit

Enter Choice: 3
Enter Name: RAM 
Enter Email: ram@gmail.com
Enter Phone Number: 9172553122
Enter Address: Pune
 
Welcome to Address Book

1. Create Address Book
2. View Address Book
3. Insert Record
4. Delete Record
5. Search Record
6. Update Record
7. Exit

Enter Choice: 2
| Name | Email | Phone Number | Address |
| JAY | jay@gmail.com | 9172553121 | Pune |
| RAM | ram@gmail.com | 9172553122 | Pune |
 
Welcome to Address Book

1. Create Address Book
2. View Address Book
3. Insert Record
4. Delete Record
5. Search Record
6. Update Record
7. Exit

Enter Choice: 
Invalid Choice
 
Welcome to Address Book

1. Create Address Book
2. View Address Book
3. Insert Record
4. Delete Record
5. Search Record
6. Update Record
7. Exit

Enter Choice: 4
Enter Name: RAM
 
Welcome to Address Book

1. Create Address Book
2. View Address Book
3. Insert Record
4. Delete Record
5. Search Record
6. Update Record
7. Exit

Enter Choice: 5
Enter Name: JAY
| JAY | jay@gmail.com | 9172553121 | Pune |
 
Welcome to Address Book

1. Create Address Book
2. View Address Book
3. Insert Record
4. Delete Record
5. Search Record
6. Update Record
7. Exit

Enter Choice: 6
Enter Name: JAY
Enter Email: jay@gmail.com
Enter Phone Number: 9172553121
Enter Address: Pune
 
Welcome to Address Book

1. Create Address Book
2. View Address Book
3. Insert Record
4. Delete Record
5. Search Record
6. Update Record
7. Exit

Enter Choice: 2
| Name | Email | Phone Number | Address |
| JAY | jay@gmail.com | 9172553121 | Pune |
 
Welcome to Address Book

1. Create Address Book
2. View Address Book
3. Insert Record
4. Delete Record
5. Search Record
6. Update Record
7. Exit

Enter Choice: 7
prathamesh@linux:~$ 

