public class Vector2 {
    double x, y;
    double vx, vy;

    public Vector2(double x, double y, double vx, double vy) {
        this.x = x;
        this.y = y;
        this.vx = vx;
        this.vy = vy;
    }

    public double getMagnitude() {
        return Math.sqrt(this.vx * this.vx + this.vy * this.vy);
    }

    public double getAngleRad() {
        return Math.atan((double) (vy / vx));
    }

    public double getAngleDeg() {
        return Math.toDegrees(this.getAngleRad());
    }

    public void setMagnitude(double magnitude) {
        magnitude = Math.abs(magnitude);

        double angleRad = this.getAngleRad();
        double angleDeg = this.getAngleDeg();

        // Notable cases
        if (Double.compare(angleDeg, (double) 0) == 0) {
            this.vx = magnitude;

        } else if (Double.compare(angleDeg, (double) 90) == 0) {
            this.vy = magnitude;

        } else if (Double.compare(angleDeg, (double) 180) == 0) {
            this.vx = -magnitude;

        } else if (Double.compare(angleDeg, (double) 270) == 0) {
            this.vy = -magnitude;

        // General cases
        } else {
            this.vx = this.getMagnitude() / (Math.sqrt(1 + Math.tan(angleRad) * Math.tan(angleRad)));
            this.vy = this.vx * Math.tan(angleRad);

            if (angleDeg > 90 && angleDeg < 180) {
                this.vx = - this.vx;

            } else if (angleDeg > 180 && angleDeg < 270) {
                this.vx = - this.vx;
                this.vy = - this.vy;

            } else if (angleDeg > 270 && angleDeg < 360) {
                this.vy = - this.vy;
            }
        }
    }
}
