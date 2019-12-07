import java.security.MessageDigest;

public class MD5Util{
	public static void main(String[] args){
		try{
			MessageDigest md5 = MessageDigest.getInstance("MD5");
			md5.update(args[0].getBytes());
			for(byte b : md5.digest())
				System.out.print(String.format("%02X", b));
			System.out.println();
		}catch(Exception e){
			e.printStackTrace();
		}

		try{
			MessageDigest md5 = MessageDigest.getInstance("MD2");
			md5.update(args[0].getBytes());
			for(byte b : md5.digest())
				System.out.print(String.format("%02X", b));
			System.out.println();
		}catch(Exception e){
			e.printStackTrace();
		}

		try{
			MessageDigest md5 = MessageDigest.getInstance("SHA-256");
			md5.update(args[0].getBytes());
			for(byte b : md5.digest())
				System.out.print(String.format("%02X", b));
			System.out.println();
		}catch(Exception e){
			e.printStackTrace();
		}

		try{
			MessageDigest md5 = MessageDigest.getInstance("SHA-512");
			md5.update(args[0].getBytes());
			for(byte b : md5.digest())
				System.out.print(String.format("%02X", b));
			System.out.println();
		}catch(Exception e){
			e.printStackTrace();
		}

		try{
			MessageDigest md5 = MessageDigest.getInstance("SHA-224");
			md5.update(args[0].getBytes());
			for(byte b : md5.digest())
				System.out.print(String.format("%02X", b));
			System.out.println();
		}catch(Exception e){
			e.printStackTrace();
		}

		try{
			MessageDigest md5 = MessageDigest.getInstance("SHA-384");
			md5.update(args[0].getBytes());
			for(byte b : md5.digest())
				System.out.print(String.format("%02X", b));
			System.out.println();
		}catch(Exception e){
			e.printStackTrace();
		}
	}
}
