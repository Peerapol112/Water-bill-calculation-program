#include <stdio.h>
#include <conio.h>

void main() 
{
    int  service = 0, choice, x[1][2]={150,300};
    float price = 0, vat = 0, total = 0,water = 0;

    //ตารางหมายเลข 2 อัตราค่าน้ำประปาพื้นที่ กปภ.สาขาภูเก็ต เกาะสมุย และเกาะพะงัน
    //กด 1) ที่อยู่อาศัย | 2) ราชการและธุรกิจขนาดเล็ก | 3) รัฐวิสาหกิจ/อุตฯ/ธุรกิจขนาดใหญ่
    printf("Program water tariffs in the area PWA branch in Phuket, Koh Samui and Koh Phangan");
    printf("\nPleas press \n1)residence  \n2)Government and small businesses \n3)state enterprise / industry / large business");
    printf("\nEnter your number : ");
    scanf("%d",&choice);

    //ขนาดมาตรน้ำ
    //กด 1) 1/2 | 2) 3/4 | 3) 1 | 4) 1 1/2 | 5) 2 | 6) 2 1/2 | 7) 3 | 8) 4 | 9) 6 | 10) >6
    printf("\nPleas press \n1) 1/2  \n2) 3/4  \n3) 1  \n4) 1 1/2  \n5) 2  \n6) 2 1/2  \n7) 3  \n8) 4  \n9) 6  \n10) >6");
    printf("\nEnter your water meter size (Service): ");
    scanf("%d",&service);

    // ใส่ปริมาณน้ำ
    // ราชการและธุรกิจขนาดเล็ก อัตราขั้นต่ำ 150 บาท / เดือน (8 ลบ.ม.)
    // รัฐวิสาหกิจ/อุตฯ/ธุรกิจขนาดใหญ่ อัตราขั้นต่ำ 300 บาท / เดือน (15 ลบ.ม.)
    printf("Enter amount of water : ");
    scanf("%f",&water);

    switch (choice)//การคำนวณค่าประปา
    {
    case 1: // ที่อยู่อาศัย
        if (water <= 10)
        {
            total = water * 10.20;
        }
        else if (water <= 20)
        {
            total = 10 * 10.20;
            water = water - 10;
            water = water * 16;
            total = total + water;
        }
        else if (water <= 30)
        {
            total = 10 * 10.20;
            water = water - 10;
            total = total+(10 * 16);
            water = water - 10;
            water = water * 19;
            total = total + water; 
        }
        else if (water <= 50) 
        {
            total = 10 * 10.20; 
            water = water - 10;  
            total = total+(10 * 16); 
            water = water - 10; 
            total = total+(10 * 19);
            water = water - 10;
            water = water * 21.20;
            total = total + water;
        }

        else if (water <= 80) //หากเดือนใดใช้น้ำมากกว่า 50 ลบ.ม./เดือน ให้คิดอัตราค่าน้ำประปาเท่ากับผู้ใช้น้ำประเภท 2 ณ เวลานั้น โดยคิดตั้งแต่ ลบ.ม.ที่ 51
        {                            //1) รับค่าปริมาณน้ำลงในตัวแปร water
            total = 10 * 10.20;      //2) นำค่าปรมาณน้ำในหน่วยแรก(10)มาคูณด้วยราคาค่าน้ำในหน่วยแรก(10.20)แล้วเก็บในตัวแปร total
            water = water - 10;      //3) นำปริมาณน้ำมาลบ(ตัวแปร water) กับหน่วยน้ำ ซึ่งอิงจากบรรทัดบน ในกรณีนี้คือ 10 แล้วเก็บไว้ในตัวแปร water
            total = total+(10 * 16); //4) นำค่าปริมาณน้ำในหน่วยที่สอง(10)คูณด้วยราคาค่าน้ำในหน่วยที่สอง(16)แล้วนำมาบวกกับตัวแปร total ในขั้นตอนที่สอง
            water = water - 10;      //5) นำปริมาณน้ำมาลบ(ตัวแปร water) กับหน่วยน้ำ ซึ่งอิงจากบรรทัดบน ในกรณีนี้คือ 10 แล้วเก็บไว้ในตัวแปร water
            total = total+(10 * 19); //6) นำค่าปริมาณน้ำในหน่วยที่สอง(10)คูณด้วยราคาค่าน้ำในหน่วยที่สาม(19)แล้วนำมาบวกกับตัวแปร total ในขั้นตอนที่สี่
            water = water - 10;      //7) นำปริมาณน้ำมาลบ(ตัวแปร water) กับหน่วยน้ำ ซึ่งอิงจากบรรทัดบน ในกรณีนี้คือ 10 แล้วเก็บไว้ในตัวแปร water
            total = total+(20 * 21.20); //8) นำค่าปริมาณน้ำในหน่วยที่สอง(20)คูณด้วยราคาค่าน้ำในหน่วยที่สี่(21.20)แล้วนำมาบวกกับตัวแปร total ในขั้นตอนที่หก
            water = water - 20;      //9) นำปริมาณน้ำมาลบ(ตัวแปร water) กับหน่วยน้ำ ซึ่งอิงจากบรรทัดบน ในกรณีนี้คือ 20 แล้วเก็บไว้ในตัวแปร water
            water = water * 24;      //10) นำปริมาณน้ำที่เป็นผลลบมาจาก บรรทัดที่เก้า (ตัวแปร water) มาคูณกับราคาค่าน้ำในหน่วยที่ห้า(24) แล้วนำมาเก็บไว้ในตัวแปร total
            total = total + water; //11) นำตัว (total) ที่ทำในขั้นตอนที่แปด มาบวกกับ ปริมาณน้ำในตัวแปร (water) ที่ทำในบรรทัดที่สิบ
        }
        else if (water <= 100)
        {
            total = 10 * 10.20;
            water = water - 10;
            total = total+(10 * 16);
            water = water - 10;
            total = total+(10 * 19);
            water = water - 10;
            total = total+(20 * 21.20);
            water = water - 20;
            total = total+(30 * 24);
            water = water - 30;
            water = water * 26;
            total = total + water;
        }
        else if (water <= 300)
        {
            total = 10 * 10.20;
            water = water - 10;
            total = total+(10 * 16);
            water = water - 10;
            total = total+(10 * 19);
            water = water - 10;
            total = total+(20 * 21.20);
            water = water - 20;
            total = total+(30 * 24);
            water = water - 30;
            total = total+(20 * 26);
            water = water - 20;
            water = water * 30.25;
            total = total + water;
        }
        else if (water <= 1000)
        {
            total = 10 * 10.20;
            water = water - 10;
            total = total+(10 * 16);
            water = water - 10;
            total = total+(10 * 19);
            water = water - 10;
            total = total+(20 * 21.20);
            water = water - 20;
            total = total+(30 * 24);
            water = water - 30;
            total = total+(20 * 26);
            water = water - 20;
            total = total+(200* 30.25);
            water = water - 200;
            water = water * 30.25;
            total = total + water;
        }
        else if (water <= 2000)
        {
            total = 10 * 10.20;
            water = water - 10;
            total = total+(10 * 16);
            water = water - 10;
            total = total+(10 * 19);
            water = water - 10;
            total = total+(20 * 21.20);
            water = water - 20;
            total = total+(30 * 24);
            water = water - 30;
            total = total+(20 * 26);
            water = water - 20;
            total = total+(200 * 30.25);
            water = water - 200;
            total = total+(700 * 30.25);
            water = water - 700;
            water = water * 30.25;
            total = total + water;
        }
        else if (water <= 3000)
        {
            total = 10 * 10.20;
            water = water - 10;
            total = total+(10 * 16);
            water = water - 10;
            total = total+(10 * 19);
            water = water - 10;
            total = total+(20 * 21.20);
            water = water - 20;
            total = total+(30 * 24);
            water = water - 30;
            total = total+(20 * 26);
            water = water - 20;
            total = total+(200 * 30.25);
            water = water - 200;
            total = total+(700 * 30.25);
            water = water - 700;
            total = total+(1000 * 30.25);
            water = water - 1000;
            water = water * 30.25;
            total = total + water;
        }
        else
        {
            total = 10 * 10.20;
            water = water - 10;
            total = total+(10 * 16);
            water = water - 10;
            total = total+(10 * 19);
            water = water - 10;
            total = total+(20 * 21.20);
            water = water - 20;
            total = total+(30 * 24);
            water = water - 30;
            total = total+(20 * 26);
            water = water - 20;
            total = total+(200 * 30.25);
            water = water - 200;
            total = total+(700 * 30.25);
            water = water - 700;
            total = total+(1000 * 30.25);
            water = water - 1000;
            total = total+(1000 * 30.25);
            water = water - 1000;
            water = water * 30.25;
            total = total + water;
        }

        break;
    case 2: //2) ราชการและธุรกิจขนาดเล็ก อัตราขั้นต่ำ 150 บาท / เดือน (8 ลบ.ม.)
        if (water <= 8)
        {
            total = x[0][0];
        }
        else if (water <= 10)
        {
            total = water * 18;
        }
        else if (water <= 20)
        {
            total = 10 * 18;
            water = water - 10;
            water = water * 21;
            total = total + water;
        }
        else if (water <= 30)
        {
            total = 10 * 18;
            water = water - 10;
            total = total+(10 * 21);
            water = water - 10;
            water = water * 22;
            total = total + water;
        }
        else if (water <= 50)
        {
            total = 10 * 18;
            water = water - 10;
            total = total+(10 * 21);
            water = water - 10;
            total = total+(10 * 22);
            water = water - 10;
            water = water * 23;
            total = total + water;
        }
        else if (water <= 80)
        {
            total = 10 * 18;
            water = water - 10;
            total = total+(10 * 21);
            water = water - 10;
            total = total+(10 * 22);
            water = water - 10;
            total = total+(20 * 23);
            water = water - 20;
            water = water * 24;
            total = total + water;
        }
        else if (water <= 100)
        {
            total = 10 * 18;
            water = water - 10;
            total = total+(10 * 21);
            water = water - 10;
            total = total+(10 * 22);
            water = water - 10;
            total = total+(20 * 23);
            water = water - 20;
            total = total+(30 * 24);
            water = water - 30;
            water = water * 26;
            total = total + water;
        }
        else if (water <= 300)
        {
            total = 10 * 18;
            water = water - 10;
            total = total+(10 * 21);
            water = water - 10;
            total = total+(10 * 22);
            water = water - 10;
            total = total+(20 * 23);
            water = water - 20;
            total = total+(30 * 24);
            water = water - 30;
            total = total+(20 * 26);
            water = water - 20;
            water = water * 30.25;
            total = total + water;
        }
        else if (water <= 1000)
        {
            total = 10 * 18;
            water = water - 10;
            total = total+(10 * 21);
            water = water - 10;
            total = total+(10 * 22);
            water = water - 10;
            total = total+(20 * 23);
            water = water - 20;
            total = total+(30 * 24);
            water = water - 30;
            total = total+(20 * 26);
            water = water - 20;
            total = total+(200 * 30.25);
            water = water - 200;
            water = water * 30.25;
            total = total + water;
        }
        else if (water <= 2000)
        {
            total = 10 * 18;
            water = water - 10;
            total = total+(10 * 21);
            water = water - 10;
            total = total+(10 * 22);
            water = water - 10;
            total = total+(20 * 23);
            water = water - 20;
            total = total+(30 * 24);
            water = water - 30;
            total = total+(20 * 26);
            water = water - 20;
            total = total+(200 * 30.25);
            water = water - 200;
            total = total+(700 * 30.25);
            water = water - 700;
            water = water * 30.25;
            total = total + water;
        }
        else if (water <= 3000)
        {
            total = 10 * 18;
            water = water - 10;
            total = total+(10 * 21);
            water = water - 10;
            total = total+(10 * 22);
            water = water - 10;
            total = total+(20 * 23);
            water = water - 20;
            total = total+(30 * 24);
            water = water - 30;
            total = total+(20 * 26);
            water = water - 20;
            total = total+(200 * 30.25);
            water = water - 200;
            total = total+(700 * 30.25);
            water = water - 700;
            total = total+(1000 * 30.25);
            water = water - 1000;
            water = water * 30.25;
            total = total + water;
        }
        else
        {
            total = 10 * 18;
            water = water - 10;
            total = total+(10 * 21);
            water = water - 10;
            total = total+(10 * 22);
            water = water - 10;
            total = total+(20 * 23);
            water = water - 20;
            total = total+(30 * 24);
            water = water - 30;
            total = total+(20 * 26);
            water = water - 20;
            total = total+(200 * 30.25);
            water = water - 200;
            total = total+(700 * 30.25);
            water = water - 700;
            total = total+(1000 * 30.25);
            water = water - 1000;
            total = total+(1000 * 30.25);
            water = water - 1000;
            water = water * 30.25;
            total = total + water;
        }
        break;
    case 3: // รัฐวิสาหกิจ/อุตฯ/ธุรกิจขนาดใหญ่ อัตราขั้นต่ำ 300 บาท / เดือน (15 ลบ.ม.)
        if (water <= 15)
        {
            total = x[0][1];
        }
        else if (water <= 20)
        {
            total = 10 * 18.50;
            water = water - 10;
            water = water * 22;
            total = total + water;
        }
        else if (water <= 30)
        {
            total = 10 * 18.50;
            water = water - 10;
            total = total +(10 * 22);
            water = water - 10;
            water = water * 26;
            total = total + water;
        }
        else if (water <= 50)
        {
            total = 10 * 18.50;
            water = water - 10;
            total = total +(10 * 22);
            water = water - 10;
            total = total +(10 * 26);
            water = water - 10;
            water = water * 29;
            total = total + water;
        }
        else if (water <= 80)
        {
            total = 10 * 18.50;
            water = water - 10;
            total = total +(10 * 22);
            water = water - 10;
            total = total +(10 * 26);
            water = water - 10;
            total = total +(20 * 29);
            water = water - 20;
            water = water * 31.50;
            total = total + water;
        }
        else if (water <= 100)
        {
            total = 10 * 18.50;
            water = water - 10;
            total = total +(10 * 22);
            water = water - 10;
            total = total +(10 * 26);
            water = water - 10;
            total = total +(20 * 29);
            water = water - 20;
            total = total +(30 * 31.50);
            water = water - 30;
            water = water * 32.50;
            total = total + water;
        }
        else if (water <= 300)
        {
            total = 10 * 18.50;
            water = water - 10;
            total = total +(10 * 22);
            water = water - 10;
            total = total +(10 * 26);
            water = water - 10;
            total = total +(20 * 29);
            water = water - 20;
            total = total +(30 * 31.50);
            water = water - 30;
            total = total +(20 * 32.50);
            water = water - 20;
            water = water * 33.50;
            total = total + water;
        }
        else if (water <= 1000)
        {
            total = 10 * 18.50;
            water = water - 10;
            total = total +(10 * 22);
            water = water - 10;
            total = total +(10 * 26);
            water = water - 10;
            total = total +(20 * 29);
            water = water - 20;
            total = total +(30 * 31.50);
            water = water - 30;
            total = total +(20 * 32.50);
            water = water - 20;
            total = total +(200 * 33.50);
            water = water - 200;
            water = water * 34.75;
            total = total + water;
        }
        else if (water <= 2000)
        {
            total = 10 * 18.50;
            water = water - 10;
            total = total +(10 * 22);
            water = water - 10;
            total = total +(10 * 26);
            water = water - 10;
            total = total +(20 * 29);
            water = water - 20;
            total = total +(30 * 31.50);
            water = water - 30;
            total = total +(20 * 32.50);
            water = water - 20;
            total = total +(200 * 33.50);
            water = water - 200;
            total = total +(700 * 34.75);
            water = water - 700;
            water = water * 34.75;
            total = total + water;
        }
        else if (water <= 3000)
        {
            total = 10 * 18.50;
            water = water - 10;
            total = total +(10 * 22);
            water = water - 10;
            total = total +(10 * 26);
            water = water - 10;
            total = total +(20 * 29);
            water = water - 20;
            total = total +(30 * 31.50);
            water = water - 30;
            total = total +(20 * 32.50);
            water = water - 20;
            total = total +(200 * 33.50);
            water = water - 200;
            total = total +(700 * 34.75);
            water = water - 700;
            total = total +(1000 * 34.75);
            water = water - 1000;
            water = water * 34.75;
            total = total + water;
        }
        else
        {
            total = 10 * 18.50;
            water = water - 10;
            total = total +(10 * 22);
            water = water - 10;
            total = total +(10 * 26);
            water = water - 10;
            total = total +(20 * 29);
            water = water - 20;
            total = total +(30 * 31.50);
            water = water - 30;
            total = total +(20 * 32.50);
            water = water - 20;
            total = total +(200 * 33.50);
            water = water - 200;
            total = total +(700 * 34.75);
            water = water - 700;
            total = total +(1000 * 34.75);
            water = water - 1000;
            total = total +(1000 * 34.75);
            water = water - 1000;
            water = water * 34.75;
            total = total + water;
        }
        break;
    default:
        break;
    }

    switch (service)//ขนาดมาตรน้ำ
    {
    case 1: // 1/2
        price = 30;
        break;
    case 2: // 3/4
        price = 50;
        break;
    case 3: // 1
        price = 60;
        break;
    case 4: // 1 1/2
        price = 90;
        break;
    case 5: // 2
        price = 350;
        break;
    case 6: // 2 1/2
        price = 450;
        break;
    case 7: // 3
        price = 450;
        break;
    case 8: // 4
        price = 550;
        break;
    case 9: // 6
        price = 950;
        break;
    case 10: // >6
        price = 1200;
        break;
    default:
        break;
    }

    printf("Sum price water = %0.2f BATH",total);
    printf("\nService = %0.2f BATH",price);
    total = total+price;
    vat = (total*7)/100;
    printf("\nVAT = %0.2f BATH",vat);
    total = total + vat;
    printf("\nTotal = %0.2f BATH",total);
}