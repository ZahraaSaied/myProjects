
package alu;

class Full_Adder_Module
{

    //Define inputs to Full_Adder_Module which are two inputs and may be previous carry in general case
    boolean x;
    boolean y;
    boolean c_in;

    //Define outpus of Full_Adder_Module which are one output of addition and carry of next phase
    boolean s;
    boolean c_out;

    // function which Calculate the sum of inputs of module
    void Calculate_sum()
    {

        boolean product1 = (!this.x) && (!this.y) && (this.c_in);
        boolean product2 = (!this.x) && (this.y) && (!this.c_in);
        boolean product3 = (this.x) && (!this.y) && (!this.c_in);
        boolean product4 = (this.x) && (this.y) && (this.c_in);

        this.s = product1 || product2 || product3 || product4;

    }

    // function which Calculate the carry of inputs of module
    void Calculate_Carry()
    {

        boolean product1 = (this.x) && (this.y);
        boolean product2 = (this.x) && (this.c_in);
        boolean product3 = (this.y) && (this.c_in);

        this.c_out = product1 || product2 || product3;

    }

    // function which Calculates the total output of module
    void Calculate_Output()
    {

        this.Calculate_sum();
        this.Calculate_Carry();

    }

}

class _4BIT_Full_Adder_Module
{

    Full_Adder_Module[] m = new Full_Adder_Module[4];

    public _4BIT_Full_Adder_Module(boolean[] num1, boolean[] num2)
    {

        for (int i = 0; i < 4; i++)
        {
            m[i] = new Full_Adder_Module();
        }

        m[0].c_in = false;

        for (int i = 0; i < 4; i++)
        {
            m[i].x = num1[i];
            m[i].y = num2[i];
        }

    }

    // function which Calculates the total output of module
    void Calculate_Output()
    {

        m[0].Calculate_Output();
        m[1].c_in = m[0].c_out;

        m[1].Calculate_Output();
        m[2].c_in = m[1].c_out;

        m[2].Calculate_Output();
        m[3].c_in = m[2].c_out;

        m[3].Calculate_Output();

        System.out.println("the output of module is : " + m[3].s + "  " + m[2].s + "  " + m[1].s + "  " + m[0].s);
        System.out.println("the carry of summation process is : " + m[3].c_out);

    }

}


class _4BIT_Subtractor_Module
{

    Full_Adder_Module[] m = new Full_Adder_Module[4];

    public _4BIT_Subtractor_Module(boolean[] num1, boolean[] num2)
    {

        for (int i = 0; i < 4; i++)
        {
            m[i] = new Full_Adder_Module();
        }

        m[0].c_in = true;

        for (int i = 0; i < 4; i++)
        {
            m[i].x = num1[i];
            m[i].y = num2[i] ^ m[0].c_in;
        }

    }

    // function which Calculates the total output of module
    void Calculate_Output()
    {

        m[0].Calculate_Output();
        m[1].c_in = m[0].c_out;

        m[1].Calculate_Output();
        m[2].c_in = m[1].c_out;

        m[2].Calculate_Output();
        m[3].c_in = m[2].c_out;

        m[3].Calculate_Output();

        System.out.println("the output of module is : " + m[3].s + "  " + m[2].s + "  " + m[1].s + "  " + m[0].s);
        System.out.println("the carry of subtarction process is : " + m[3].c_out);

    }

}


class Complement_Module
{
// in
    boolean x;
// out
    boolean y;

    // function which Calculate the complement of inputs of module
    void Calculate_Complement()
    {

        this.y= !this.x;

    }

    // function which Calculates the total output of module
    void Calculate_Output()
    {

        this.Calculate_Complement();

    }

}

class _4BIT_Complement_Module
{

    Complement_Module [] m = new Complement_Module [4];

    public _4BIT_Complement_Module (boolean[] num1)
    {

        for (int i = 0; i < 4; i++)
        {
            m[i] = new Complement_Module ();
        }

        for (int i = 0; i < 4; i++)
        {
            m[i].x = num1[i];
        }

    }
    void Calculate_Output()
    {

        for (int i = 0; i < 4; i++)
        {
            m[i].Calculate_Output();

        }

        System.out.println("the output of module is : " + m[0].y + " " + m[1].y + " " + m[2].y + " " + m[3].y );

    }
}






class Anding_Module
{
// in
    boolean x;
    boolean y;
// out
    boolean z;

    // function which Calculate the anding of inputs of module
    void Calculate_Anding()
    {

        this.z= this.x&&this.y;

    }

    // function which Calculates the total output of module
    void Calculate_Output()
    {

        this.Calculate_Anding();

    }

}

class _4BIT_Anding_Module
{

    Anding_Module [] m = new Anding_Module [4];

    public _4BIT_Anding_Module (boolean[] num1, boolean[] num2)
    {

        for (int i = 0; i < 4; i++)
        {
            m[i] = new Anding_Module ();
        }

        for (int i = 0; i < 4; i++)
        {
            m[i].x = num1[i];
            m[i].y = num2[i];
        }

    }

    void Calculate_Output()
    {

        for (int i = 0; i < 4; i++)
        {
            m[i].Calculate_Output();

        }

        System.out.println("the output of module is : " + m[0].z + " " + m[1].z + " " + m[2].z + " " + m[3].z);

    }
}

public class ALU
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        // TODO code application logic here

        boolean[] num1 = {true, true, true, true};
        boolean[] num2 = {true, true, true, true};

        _4BIT_Full_Adder_Module FA = new _4BIT_Full_Adder_Module(num1, num2);
        _4BIT_Complement_Module C = new _4BIT_Complement_Module(num1);
        _4BIT_Anding_Module A = new _4BIT_Anding_Module(num1, num2);
        _4BIT_Subtractor_Module S = new _4BIT_Subtractor_Module(num1,num2);

        System.out.println("the result of full adder");
        FA.Calculate_Output();
        System.out.println("the result of Complement ");
        C.Calculate_Output();
        System.out.println("the result of Anding ");
        A.Calculate_Output();
        System.out.println("the result of Subtracting ");
        S.Calculate_Output();

    }

}
