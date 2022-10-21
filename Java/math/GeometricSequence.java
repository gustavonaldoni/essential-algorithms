public class GeometricSequence {
    float firstTerm;
    float commonRatio;

    public GeometricSequence(float firstTerm, float commonRatio) {
        this.firstTerm = firstTerm;
        this.commonRatio = commonRatio;
    }

    public float generalTerm(int n) {
        float result;

        if (n > 0) {
            result = this.firstTerm * (float) (Math.pow(this.commonRatio, n - 1));
        }

        else {
            result = -1.0f;
        }

        return result;
    }

    public float finiteSum(int n) {
        float result;

        if (n > 0) {
            result = (this.firstTerm * (float) (Math.pow(this.commonRatio, n) - 1)) / (this.commonRatio - 1); 
        }

        else {
            result = -1.0f;
        }

        return result;
    }

    public float infiniteSum(int n) {
        float result;

        if (n > 0 && n > -1 && n < 1) {
            result = this.firstTerm / (1 - this.commonRatio); 
        }

        else {
            result = -1.0f;
        }

        return result;
    }

}
