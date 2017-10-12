/*
 * 获取2008年8月8日是星期几
 */
import java.util.Calendar;

public class CalendarTest {
    public static void main(String[] args) {
        Calendar c = Calendar.getInstance(); // 获取系统当前日历
        c.set(2008, Calendar.AUGUST, 8); // 设置日历时间为2008年8月8日
        //c.setFirstDayOfWeek(Calendar.MONDAY);
    
        // 获取2008年8月8日是一星期中的第几天
        int i = c.get(Calendar.DAY_OF_WEEK);

        char week = '日';
        switch (i) {
            case 2: week = '一'; break;
            case 3: week = '二'; break;
            case 4: week = '三'; break;
            case 5: week = '四'; break;
            case 6: week = '五'; break;
            case 7: week = '六'; break;
        }

        System.out.println("2008年8月8日是星期" + week);
    }
}
