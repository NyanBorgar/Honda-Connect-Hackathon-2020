HONDA HACKATHON - TEAM NOMAD
=========================================================================
There are two Proof of Concepts (POC) described in this phase submission:
- Personalization 
- Data Log
=========================================================================
In Personalization:
- Note that none of the team members are capable of Android Development. Hence the POC is demonstrated using Web App.
- Home Screen shows the demonstration of User being able to configure the journeys with time and date setup. Eg: setup a destination to Work from the House at 8:30AM from Monday to Friday. This can be later mapped into the voice assist.
- Preference Option shows all the personalization features that enable or disable some of the features of the application for optimal use of the app with convenience to the user. This can be later used to configure the voicw assist and other corresponding features.
- About us: Redirects to the original website
- Diagnosis: Upon clicking the start Diagnosis, the linear regression algorithm fetches the data from the recent data logs and performs linear regression and outputs the condition of the engine followed by the estimated time in which the engine needs to be serviced. This can be mapped into the voice assist for more optimal functionality.
=========================================================================
In Data Log:
- Note that for the POC of data log, the microcontroller used is an Arduino Nano. However the concept can be mapped into any microcontroller of the Honda's Convenience
- The microcontroller firmware program is stored in the mc_main_datalog.ino file.
- A Python Program called data_log_algo.py is used to perform linear regression and returns the Current Engine Condition and the estimated time required for the engine to reduce a certain threshold of engine condition. 
=========================================================================

======END OF README======