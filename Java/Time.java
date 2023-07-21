import java.time.*;
public class Time {
 private int hour;
 private int minute;
 private int second;
 private LocalDateTime time;
 public Time(LocalDateTime time) {
  this.time = time;
 }
 public int getHour() {
  return time.getHour();
 }
 public int getMinute() {
  return time.getMinute();
 }
 public int getSecond() {
  return time.getSecond();
 }
 public static void main(String[] args) {
  Time time_logged = new Time(LocalDateTime.now());
  int this_hour = time_logged.getHour();
  System.out.println(this_hour);
 }
}