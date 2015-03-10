import QtQuick 2.3
import QtQuick.Controls 1.1
import Material 0.1
import Material.ListItems 0.1 as ListItem

ApplicationWindow {
    id: appWindow
    visible: true
    width: 800
    height: 480
    title: qsTr("Abbey Ridge Automated Brewery")
    initialPage: myPage
    theme {
        primaryColor: "#993333"
        accentColor: "#999"
    }
    Page{
        id: myPage
        title: "Abbey Ridge Automated Brewery"
        anchors.fill: parent
        tabs: [
            {text: "Recipe"},
            {text: "Prep"},
            {text: "Mash"},
            {text: "Sparge"},
            {text: "Chill"}
        ]

        TabView {
            id: tabView
            model: tabs
            anchors.fill: parent
            currentIndex: myPage.selectedTab
        }

        VisualItemModel{
            id: tabs
            Rectangle{
                id: recipePage
                width: tabView.width
                height: tabView.height
                color: "#999"
            }
            Rectangle{
                id: prepPage                
                width: tabView.width
                height: tabView.height
                color: "#999"
                Item{
                    id: prep_temperature
                    width: parent.width/2
                    height: parent.height


                    TemperatureCard{}
                }
                Item{
                    id: section_preptimers
                    width: parent.width/2
                    height: parent.height
                    anchors.right: parent.right
                    TimerCard{
                        id: timerCard_prep
                    }
                }

            }

            Rectangle{
                id: mashPage
                width: tabView.width
                height: tabView.height
                color: "#999"
                Item{
                    id: mash_temperature
                    width: parent.width/2
                    height: parent.height/2

                    TemperatureCard{}
                }
                Item{
                    id: section_mashtimers
                    width: parent.width/2
                    height: parent.height
                    anchors.right: parent.right
                    TimerCard{
                        id: timerCard_mash
                    }
                }
                Item {
                    anchors.top: mash_temperature.bottom
                    anchors.left: parent.left
                    anchors.margins: 20
                    Button{
                        id: btn_startSparge
                        text: "Begin Sparge"
                        elevation: 1
                        onClicked: myPage.selectedTab = 3
                    }
                }
            }

            Rectangle{
                id: spargePage
                width: tabView.width
                height: tabView.height
                color: "#999"
                Item{
                    id: sparge_temperature
                    width: parent.width/2
                    height: parent.height/2

                    TemperatureCard{}
                }
                Item{
                    id: section_spargetimers
                    width: parent.width/2
                    height: parent.height
                    anchors.right: parent.right
                    TimerCard{
                        id: timerCard_sparge
                    }
                }
                Item{
                    id: sparge_pumpControl
                    width: parent.width/2
                    height: parent.height
                    anchors.top: sparge_temperature.bottom
                    anchors.left: parent.left

                    PumpControls{}
                }
            }
            Rectangle{
                id: chillPage
                width: tabView.width
                height: tabView.height
                color: "#999"
                Item{
                    id: chill_temperature
                    width: parent.width/2
                    height: parent.height/2

                    TemperatureCard{
                        id: thermoCard_chill
                    }
                }
                Item{
                    id: section_chilltimers
                    width: parent.width/2
                    height: parent.height
                    anchors.right: parent.right
                    TimerCard{
                        id: timerCard_chill
                    }
                }
                Item{
                    id: chill_pumpControl
                    width: parent.width/2
                    height: parent.height
                    anchors.top: chill_temperature.bottom
                    anchors.left: parent.left

                    PumpControls{}
                }


            }
        }
    }
    Snackbar{
        id: snackbar
    }
}
//                    Rectangle{
//                        id: debug_rect
//                        visible: false
//                        anchors.fill: parent
//                        color: "blue"
//                    }
