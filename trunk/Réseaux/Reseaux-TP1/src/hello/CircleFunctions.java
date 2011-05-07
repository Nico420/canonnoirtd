package hello;

import java.util.Scanner;

import javax.jws.WebService;
import javax.jws.WebMethod;
import javax.xml.ws.Endpoint;

@WebService
public class CircleFunctions {
	@WebMethod
	public double getArea(double r) {
		return java.lang.Math.PI * (r * r);
	}

	@WebMethod
	public double getCircumference(double r) {
		return 2 * java.lang.Math.PI * r;
	}

	@WebMethod
	public double add(double r, double s) {
		return s + r;
	}

	@WebMethod
	public double sub(double r, double s) {
		return r - s;
	}

	@WebMethod
	public double mul(double r, double s) {
		return s * r;
	}

	@WebMethod
	public double div(double r, double s) {
		return r / s;
	}

	public void calculatrice() {
		System.out.println("Calculatrice");
		System.out.println("Choisissez votre mode de calcul : ");
		System.out.println("(1) Addition");
		System.out.println("(2) Multiplication");
		System.out.println("(3) Soustraction");
		System.out.println("(4) Division");
		System.out.println("Votre Choix : ");
		Scanner sc = new Scanner(System.in);
		int choix = 0;

		// while(choix!=1 || choix!=2 || choix!=3 || choix!=4){
		choix = sc.nextInt();
		// }
		System.out.println("Nombre 1 : ");
		double a = sc.nextDouble();
		System.out.println("Nombre 2 : ");
		double b = sc.nextDouble();
		double res = 0;
		switch (choix) {
		case 1:
			res = add(a, b);
			break;
		case 2:
			res = mul(a, b);
			break;
		case 3:
			res = sub(a, b);
			break;
		case 4:
			res = div(a, b);
			break;
		default:
			break;
		}
		System.out.println("Resultat : " + res);
	}

	public static void main(String[] args) {

		Endpoint.publish(
				"http://localhost:8080/WebServiceExample/circlefunctions",
				new CircleFunctions());

	}
}