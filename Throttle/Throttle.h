#ifndef THROTTLE_H
#define THROTTLE_H

class throttle
{
    public:
        throttle();
        ~throttle();
        
                /**
         * Initializes the throttle to a top position of initial_top_position and
         * fully shut off.
         */
        throttle(int initial_top_position);
        
        // mutators
        void shut_off();

        void shift(int amount);

        // accessors
        double flow() const;

        bool is_on() const;
    
    private:
        int position;
        int top_position;

};

#endif // THROTTLE_H
