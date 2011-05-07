package net.webservicex;

public class Client{
	public static void main(String[] args) {
		System.setProperty("http.proxyPort", "8080");
		System.setProperty("http.proxyHost", "proxy.insa-rennes.fr");
		
		net.webservicex.SendSMS t = new SendSMS();
		t.setMessage("Test");
		t.setMobileNumber("689587");
		t.setFromEmailAddress("nicolas.desfeux@insa-rennes.fr");
		t.setCountryCode("33");
		SendSMSWorld t2 = new net.webservicex.SendSMSWorld();
		net.webservicex.SendSMSWorldSoap port = t2.getSendSMSWorldSoap();
		
		port.sendSMS("nicolas.desfeux@insa-rennes.Fr","33", "683005089", "Salut gros daron");
		
		
		GetSunSetRiseTime g = new GetSunSetRiseTime();
		LatLonDate l = new LatLonDate();
		l.setDay(28);
		l.setMonth(01);
		l.setYear(2011);
		l.setLatitude((float)-48.07);
		l.setLongitude((float)1.41);
		SunSetRiseService s = new SunSetRiseService();
		LatLonDate date = s.getSunSetRiseServiceSoap().getSunSetRiseTime(l);
		System.out.println(date.getSunRiseTime());
		System.out.println(date.getSunSetTime());
		
    }
}
