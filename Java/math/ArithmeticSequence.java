public class ArithmeticSequence {
    float firstTerm;
    float commonDifference;

    public ArithmeticSequence(float firstTerm, float commonDifference) {
        this.firstTerm = firstTerm;
        this.commonDifference = commonDifference;
    }

    public float generalTerm(int n) {
        float result;

        if (n > 0) {
            result = this.firstTerm + (n - 1) * this.commonDifference;
        }

        else {
            result = -1.0f;
        }

        return result;
    }

    public float finiteSum(int n) {
        float result;

        if (n > 0) {
            result = (this.firstTerm + this.generalTerm(n)) * (n / 2); 
        }

        else {
            result = -1.0f;
        }

        return result;
    }
}