package Testing;


import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;


public class BaseSalaryTests {

    public BaseSalaryTests() {
    }

    @BeforeClass
    public static void setUpClass() {
    }

    @AfterClass
    public static void tearDownClass() {
    }

    @Before
    public void setUp() {
    }

    @After
    public void tearDown() {
    }

    private float calcMoney(ArrayList<MoneyScheme> Money, ArrayList<Lesson> WorkHours) {

        try {

            float sum = 0;

            for (Lesson less : WorkHours) {

                for (int i = 0; i < Money.size() - 1; i++) {
                    if ((Money.get(i).dat.compareTo(less.dat) < 0) && (Money.get(i + 1).dat.compareTo(less.dat) > 0)) {

                        System.out.println("");
                        System.out.println("");
                   //  System.out.println("**** This date passes the check: " + less.dat+ " ****");

                        //multiply with the lowest date
                        System.out.println(less.dat + " : " + Money.get(i).dat);
                        sum += less.Duration * Money.get(i).Money;

                    }

                }
                

            // check for equality between the less.dat and money.dat
                //BUT NOT WITH THE LAST ELEMENT!!!!!!
                for (int w=0;w<Money.size()-1;w++) {
                    if (Money.get(w).dat.equals(less.dat) == true) {

                        System.out.println("");
                        System.out.println("");
                   //  System.out.println("**** This date passes the check: " + less.dat+ " ****");

                        //multiply with the lowest date
                        System.out.println(less.dat + " : " + Money.get(w).dat);
                        sum += less.Duration * Money.get(w).Money;

                    }

                }

                
                //if its greater than the last date ...
                if (less.dat.after(Money.get(Money.size() - 1).dat)) {
                    System.out.println(less.dat + " : " + Money.get(Money.size() - 1).dat);

                    sum += less.Duration * Money.get(Money.size() - 1).Money;
                }
                
                
            }
            return sum;
        } catch (Exception ex) {
            System.out.println(ex.toString());

            return -100;
        }
    }

    @Test
    public void TestFeeAlgorithm() {
        // what about extra salary ??????
        ArrayList<MoneyScheme> salaire = new ArrayList<MoneyScheme>();
        ArrayList<Lesson> wHours = new ArrayList<Lesson>();

        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");

        try {
            MoneyScheme m = new MoneyScheme();

            m.dat = sdf.parse("10/01/2015");
            m.Money = 8;

            salaire.add(m);

            m = new MoneyScheme();

            m.dat = sdf.parse("20/02/2015");
            m.Money = 6;

            salaire.add(m);

            m = new MoneyScheme();

            m.dat = sdf.parse("20/04/2015");
            m.Money = 5.5f;

            salaire.add(m);

            //---------------------------------------------
            Lesson ls = new Lesson();
            ls.Duration = 6;
            ls.dat = sdf.parse("11/01/2015");
            wHours.add(ls);

            ls = new Lesson();
            ls.Duration = 10;
            ls.dat = sdf.parse("19/01/2015");
            wHours.add(ls);

            ls = new Lesson();
            ls.Duration = 2;
            ls.dat = sdf.parse("20/02/2015");
            wHours.add(ls);

            ls = new Lesson();
            ls.Duration = 5;
            ls.dat = sdf.parse("20/03/2015");
            wHours.add(ls);

            ls = new Lesson();
            ls.Duration = 5;
            ls.dat = sdf.parse("28/03/2015");
            wHours.add(ls);

            ls = new Lesson();
            ls.Duration = 2;
            ls.dat = sdf.parse("24/04/2015");
            wHours.add(ls);
            
       
            

            assertEquals(211.0f, calcMoney(salaire, wHours), 0.03f);

        } catch (Exception ex) {
            System.out.println(ex.toString());
        }

    }
    
    
    
    
    
    
    
    
    
    
    
      @Test
     public void TestFeeTwo() {
        // what about extra salary ??????
        ArrayList<MoneyScheme> salaire = new ArrayList<MoneyScheme>();
        ArrayList<Lesson> wHours = new ArrayList<Lesson>();

        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");

        try {
            MoneyScheme m = new MoneyScheme();

            m.dat = sdf.parse("10/01/2015");
            m.Money = 8;

            salaire.add(m);

            m = new MoneyScheme();

            m.dat = sdf.parse("20/02/2015");
            m.Money = 6;

            salaire.add(m);

            m = new MoneyScheme();

            m.dat = sdf.parse("20/04/2015");
            m.Money = 5.5f;
            salaire.add(m);
            
            
            m.dat = sdf.parse("24/04/2015");
            m.Money = 5.5f;

            salaire.add(m);

            //---------------------------------------------
            Lesson ls = new Lesson();
            ls.Duration = 6;
            ls.dat = sdf.parse("11/01/2015");
            wHours.add(ls);

            ls = new Lesson();
            ls.Duration = 10;
            ls.dat = sdf.parse("19/01/2015");
            wHours.add(ls);

            ls = new Lesson();
            ls.Duration = 2;
            ls.dat = sdf.parse("20/02/2015");
            wHours.add(ls);

            ls = new Lesson();
            ls.Duration = 5;
            ls.dat = sdf.parse("20/03/2015");
            wHours.add(ls);

            ls = new Lesson();
            ls.Duration = 5;
            ls.dat = sdf.parse("28/03/2015");
            wHours.add(ls);

            ls = new Lesson();
            ls.Duration = 2;
            ls.dat = sdf.parse("24/04/2015");
            wHours.add(ls);
            
       
            ls = new Lesson();
            ls.Duration = 36.5f;
            ls.dat = sdf.parse("24/04/2015");
            wHours.add(ls);
            

            assertEquals(411.75f, calcMoney(salaire, wHours), 0.03f);

        } catch (Exception ex) {
            System.out.println(ex.toString());
        }

    }

    /* a history of the wages e.g
     01 January 2015 8.5
     11 January 2015 8.0
     21 January 2015 6
            
     or a history of the tuition fees
     */
    class MoneyScheme {

        Date dat;
        float Money;

    }

    /* a history of the working hours
     01 January 2015 2 hours
     11 January 2015 1.0 hour
     21 January 2015 1.3 hours
     */
    class Lesson {

        Date dat;
        float Duration;

    }

}
