package hello;

import java.util.Scanner;

public class ClientCircleFunctions {
	public static void main(String[] args) {
		System.out.println("a");
		try { // Call Web Service Operation
           hello.CircleFunctionsService service =
                new hello.CircleFunctionsService();
            hello.CircleFunctions port = service.getCircleFunctionsPort();
            // TODO initialize WS operation arguments here
            double arg0 = 3.0;
            double arg1 = 3.0;
            // TODO process result here
            double result = port.getArea(arg0);
            System.out.println("Result = "+result);
            System.out.println("Addition 3+3 :"+port.add(arg0, arg1));
            System.out.println("Soustraction 3-3 :"+port.sub(arg0, arg1));
            System.out.println("Multiplication 3*3 :"+port.mul(arg0, arg1));
            System.out.println("Division 3/3 :"+port.div(arg0, arg1));
            port.calculatrice();
        } catch (Exception ex) {
            // TODO handle custom exceptions here
        }
        // TODO code application logic here
    }

}
