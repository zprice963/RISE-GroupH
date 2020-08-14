# Modeling the Effects of Social Isolation on Serotonergic Neurons by Upregulating Calcium-Activated Potassium Channels 

### Caledonia Grant (1,4), David Park (2,4), Zoe Price (3,4), Samad Shaikh (2,4), Dr. Marianne Bezaire (4)

Ripon High School, 850 Tiger Dr, Ripon, WI 54971 (1); Northview High School, 10625 Parsons Rd, Johns Creek, GA 30097 (2); The Kinkaid School, 201 Kinkaid School Dr, Houston, TX 77024 (3);  Boston University, Boston, MA 02215 (4)

This project was conducted as a part of Boston University's Research in Science and Engineering program over the summer of 2020.

--------------------------------------------------------------------------------------------

## Poster

## Research Paper

### Background
The world we currently live in has become a strange and turbulent place. The last five months have been an emotional roller coaster as a result of cancelled activities, the uncertain future, and quarantine associated with the pandemic. Interestingly, 53% of American adults believe that the pandemic is taking a toll on their mental health, and many have reported symptoms of depression and/or anxiety due to social isolation. In order to gain a better understanding of how the coronavirus is affecting mental health and brain physiology, this project looks at how social isolation is causing depression-like symptoms in certain individuals. Of course, this project focuses on just one aspect of the effect of isolation, but it offers an explanation for why many people are suffering from symptoms of depression without social interaction.

### Introduction
Depression is a mental health disorder characterized by a persistently depressed mood or a loss of interest in activites, causing a significant impairment in patient's daily lives. While there are many potential causes of depression, the monoamine hypothesis predicts that the underlying pathophysologic basis of depression is a depletion in the levels of certain neurotransmitters in the central nervous system, such as serotonin, also known as 5-HT (Jesulola et al., 2018). A significant portion of the serotonin innervation to the forebrain comes from the dorsal raphe nucleus (DRN), the largest serotonergic nucleus in the brain, and it is known that Social Isolation Stress (SIS) renders mouse DRN serotonergic neurons less responsive to stimulation (Sargin et al., 2016). In mice, chronic social isolation upregulates SK3 channels, a type of small-conductance calcium-activated potassium channel, which causes a reduction in excitability in the 5-HT neuron (Sargin et al., 2016). This decrease in excitability means the neuron is less likely to fire, significantly lowering the amount of serotonin released in the brain and likely leading to the anxiety and depressive-like behaviors associated with social isolation (Sargin et al., 2016). This study examines the possibility of down-regulating these SK3 channels as a method of increasing 5-HT levels in the DRN of humans.

### Methods
This code models a serotonergic neuron in the dorsal raphe nucleus under the conditions of social isolation. Using code modeling a dopamine neuron in the same region of the brain from Dougalis et al., a model was developed by altering the neuron's properties and adding calcium-activated potassium channels to more closely resemble a serotonin neuron. The neuron's behavior was validated with in vitro neurophysiological data from Tuckwell et al. before conducting any analysis. In order to replicate 5-HT neuron conditions seen in rodents with Social Isolation Stress (SIS), SK3 channel conductance was modified, as well as the flow of calcium ions. This allowed the generation of data similar to that seen in the study conducted by Sargin et al. The firing rates of the cell were then simulated using the model for various time intervals, up to the firing rate over a course of 10 weeks. The data was then analyzed to determine the decrease in firing rate per day as a result of the modification of SK3 channels and calcium ion voltage, assuming a sigmoidal relationship between the increase in SK3 channel conductance and isolation day. Further modification of calcium ion voltage was then analyzed as a possible therapeutic target for SIS depression-like symptoms.

### Results

Graph 1: Firing Rate (Hz) vs. Maximum Ionic Conductance (S/cm^2)

Graph 2: Change in Firing Rate (%) vs. Change in Maximum Ionic Conductance from Healthy Cell (%)

Graph 3: Change in Firing Rate (%) vs. Social Isolation Period (Weeks)

Figure 1: Firing Patterns

### Discussion
This project reveals that increasing the conductance of the calcium-activated potassium channels decreases the firing rate of the serotonin neuron, and the graph shows a sigmoidal relationship between the conductance of these channels and the firing rate of the neuron. Furthermore, our project reveals that prolonged social isolation stress does have significant long-term effects on serotonin pathways in the brain: the data shows that increasing the time interval of isolation decreases the firing rate of the serotonin neuron even more, showing that longer social isolation is more likely to lead to stronger symptoms of depression. Of course, this project does have limitations. For example, this project was based on a computational model of a dopamine neuron in the dorsal raphe nucleus, not a serotonin neuron. This could have an effect on the firing rates measured by the model and the effects of the SK channel on the neuron. Furthermore, in order to have the model neuron behave normally, changes in the concentration of each type of channel were made, and these changes may not accurately resemble the channel concentrations in the serotonin neuron. However, this model still gives an accurate representation of how SK channel regulation impacts a serotonin neuron in the dorsal raphe nucleus, and therefore, this model could help in the development of depression treatments. Most current antidepressants are selective serotonin reuptake inhibitors (SSRIs), which work by blocking the uptake of serotonin by the presynaptic neuron, allowing the serotonin to remain in the synapse and continue to stimulate the postsynaptic neuron. However, if the serotonin neuron is not firing as frequently due to upregulation of the SK3 channel, these SSRI drugs will not have much of an effect, as there will not be much serotonin released into the synapse to stimulate the postsynaptic neuron. By targeting the SK3 channels on DRN serotonin neurons, future antidepressants could help modulate the firing rate of these neurons, ensuring enough serotonin is constantly released into the synapse, and our research provides accurate measurements of the exact effects of calcium-activated potassium channel regulation.

### References
David, D. J., & Gardier, A. M. (2016). Les bases de pharmacologie fondamentale du système sérotoninergique : application à la réponse antidépressive [The pharmacological basis of the serotonin system: Application to antidepressant response]. L'Encephale, 42(3), 255–263. 
Deignan, J., Luján, R., Bond, C., Riegel, A., Watanabe, M., Williams, J. T., Maylie, J., & Adelman, J. P. (2012). SK2 and SK3 expression differentially affect firing frequency and precision in dopamine neurons. Neuroscience, 217, 67–76. 
Dougalis, A. G., Matthews, G., Liss, B., & Ungless, M. A. (2017). Ionic currents influencing spontaneous firing and pacemaker frequency in dopamine neurons of the ventrolateral periaqueductal gray and dorsal raphe nucleus (vlPAG/DRN): A voltage-clamp and computational modelling study. Journal of computational neuroscience, 42(3), 275–305. 
Hashemi, P., Dankoski, E. C., Lama, R., Wood, K. M., Takmakov, P., & Wightman, R. M. (2012). Brain dopamine and serotonin differ in regulation and its consequences. PNAS, 11510-11515. 
Jesulola, E., Micalos, P., & Baguley, I. J. (2018). Understanding the pathophysiology of depression: From monoamines to the neurogenesis hypothesis model - are we there yet? Behavioural Brain Research, 341, 79–90. 
Peng, M., Mo, B., Liu, Y., Xu, M., Song, X., Liu, L., Fang, Y., Guo, T., Ye, J., Yu, Z., Deng, Q., & Zhang, X. (2020). Prevalence, risk factors and clinical correlates of depression in quarantined population during the COVID-19 outbreak. Journal of Affective Disorders, 275, 119–124. 
Sargin, D., Oliver, D. K., & Lambe, E. K. (2016). Chronic social isolation reduces 5-HT neuronal activity via upregulated SK3 calcium-activated potassium channels. ELife, 5. doi:10.7554/elife.21416
Tuckwell, H. C., & Penington, N. J. (2014). Computational modeling of spike generation in serotonergic neurons of the dorsal raphe nucleus. Progress in neurobiology, 118, 59–101. 


### Acknowledgements
Thank you to:
- Dr. Marianne Bezaire, for teaching us during the course of the RISE program and helping us code our model
- Yiwen Gu, Scott Knudstrup, Wenxing Liu, and Feiyuan Yu, for answering all of our questions, as well as for helping us develop our project idea and presentation
- Dr. Amanda Kautzman, for organizing an amazing program and putting together a fantastic symposium
- Ms. Kaitlyn Dorst, for helping us develop a deeper understanding of neuroscience and delivering fascinating lectures each morning
- the Boston University faculty, for making this program happen
