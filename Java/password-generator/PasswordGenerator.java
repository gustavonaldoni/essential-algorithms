import java.util.Random;

public class PasswordGenerator {

    private String lowercaseCharacters;
    private String uppercaseCharacters;
    private String specialCharacters;
    private String numbers;

    public PasswordGenerator() {
        this.lowercaseCharacters = "abcdefghijklmnopqrstuvwxyz";
        this.uppercaseCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        this.specialCharacters = "/.,;*&^()#@!";
        this.numbers = "0123456789";
    }

    public String generate(int securityLevel, int size) {
        String characters = "";
        String password = "";
        int i, randomIndex;

        Random rand = new Random();

        if (securityLevel > 4)
            securityLevel = 4;

        for (i = 1; i <= securityLevel; i++) {
            if (i == 1)
                characters += this.lowercaseCharacters;

            if (i == 2)
                characters += this.uppercaseCharacters;

            if (i == 3)
                characters += this.numbers;

            if (i == 4)
                characters += this.specialCharacters;
        }

        for (i = 0; i < size; i++) {
            randomIndex = rand.nextInt(characters.length());
            password += characters.charAt(randomIndex);
        }

        return password;
    }
}