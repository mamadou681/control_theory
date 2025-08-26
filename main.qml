import QtQuick 2.2 //15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15


import CustomPlot 1.0
import Filters 1.0
//import ControlTheory 1.0

Window {
    id: root
    width: 800
    height: 600
    visible: true
    title: qsTr("Hello World")

    property int selected: 0
    property double sampleRateFreq: parseFloat(sampleRateTextField.text)
    property double time: 0


    Rectangle {
        id: header
        width: 200
        height: 20
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            id: title
            text: qsTr("Real time plot")
            font.pointSize: 14
            font.bold: true
        }
    } // header

    property real currentAvgFilterValue: 0.0

    function showFilterParameter(type) {
        switch(type) {
        case 0:
            wiwndowRow.visible = false
            alphaRow.visible = false
            break
        case 1:
            wiwndowRow.visible = true
            alphaRow.visible = false
            break;
        case 2:
            alphaRow.visible = true
            wiwndowRow.visible = false
            break;
        case 3:
            wiwndowRow.visible = false
            alphaRow.visible = false
            break;
        case 4:
            wiwndowRow.visible = false
            alphaRow.visible = false
            break;
        default:
            break;
        }

    }

    function replotGraph(secondPlot, xLabel, yLabel, filterType, param, note, firstPlot, deltaT) {
        filterManager.resetFilter(filterType, param, deltaT)
        qCustomPlotWrapper.resetGraph()
        qCustomPlotWrapper.setupGraph(secondPlot, xLabel, yLabel, firstPlot)

        repeater.itemAt(root.selected).time = 0

    }
    Column {
        id: filterParameter
        property real param: alphaRow.visible ? parseFloat(alphaTextField.text) :
                                                parseFloat(windowSizeTextField.text)
        spacing: 4
        anchors.top: header.top
        anchors.right: featureContainer.left
        anchors.rightMargin: 14
        Text {
            id: titleParam
            text: qsTr("Filter Parameter")
            font.bold: true
            font.pointSize: 10
            anchors.horizontalCenter: wiwndowRow.horizontalCenter
        }
        Row {
            id: sampleRate
//            visible: false
            Text {
                id: sampleRateText
                text: qsTr("Sample rate: ")
                anchors.verticalCenter: sampleRateTextField.verticalCenter
            }
            TextField {
                id: sampleRateTextField
                text: "100"
                width: 60

                onTextChanged: {
                    root.time = 0
                   replotBtn.clicked()
                }
            }
            Text {
                id: unitSampleRate
                anchors.verticalCenter: sampleRateTextField.verticalCenter
                text: qsTr(" Hz")
            }
        }
        Row {
            id: wiwndowRow
            visible: false
            Text {
                id: windowSizeText
                text: qsTr("Window's size: ")
                anchors.verticalCenter: windowSizeTextField.verticalCenter
            }
            TextField {
                id: windowSizeTextField
                text: "10"
                width: 40
            }
        }

        Row {
            id: alphaRow
            visible: false
            Text {
                id: alpha
                text: qsTr("Alpha: ")
                width: windowSizeText.width
                anchors.verticalCenter: alphaTextField.verticalCenter
            }
            TextField {
                id: alphaTextField
                text: "0.3"
                width: 40

            }
        }

        Button {
            id: replotBtn
            text: "Replot"
            enabled: alphaRow.visible || wiwndowRow.visible
            anchors.horizontalCenter: wiwndowRow.horizontalCenter

            onClicked: {
                repeater.itemAt(root.selected).param = filterParameter.param
                console.log("repeater.itemAt(root.selected).param: ",
                            repeater.itemAt(root.selected).param, filterParameter.param)

                replotGraph(repeater.itemAt(root.selected).secondPlot,
                            repeater.itemAt(root.selected).xLabel,
                            repeater.itemAt(root.selected).yLabel,
                            repeater.itemAt(root.selected).filterType,
                            repeater.itemAt(root.selected).param,
                            repeater.itemAt(root.selected).note,
                            repeater.itemAt(root.selected).firstPlot,
                            1/root.sampleRateFreq)

            }

        } // Replot btn

    }//filterParameter

    Row {
        id: timerControl
        anchors.top: header.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: header.horizontalCenter

        spacing: 5

        Text {
            text: qsTr("Current filter value: ")
            anchors.verticalCenter: textField.verticalCenter
        }
        TextField {
            id: textField
            text: currentAvgFilterValue.toString()
            readOnly: true
        }
        Button {
            text: "Run"

            onClicked: {
                repeater.itemAt(selected).timerBtn.start()

            }
        }

        Button {
            text: "Stop"

            onClicked: {
                repeater.itemAt(selected).timerBtn.stop()
            }
        }

    } // timerControl

    Rectangle {
        id: featureContainer
        width: root.width/1.5 //featureComp.width
        height: root.height //featureComp.height
        //        color: "grey"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: timerControl.bottom
        anchors.topMargin: 25

        Row {
            id: featureComp
            width:  parent.width
            height: parent.height



            FilterManager {
                id: filterManager
            }
            Flickable {
                id: flickButton
                flickableDirection: Flickable.VerticalFlick
                //                boundsBehavior: Flickable.StopAtBounds
                width: 128
                height: parent.height /2
                contentWidth: width
                contentHeight: columnContainer.height

                clip:           true

                ScrollBar.vertical: ScrollBar {
                    policy: ScrollBar.AlwaysOn
                }
                Column {
                    id: columnContainer
                    spacing: 5
                    anchors.left: parent.left
                    anchors.right: parent.right
                    Repeater {
                        id: repeater
                        model: filterManager.filterModel

                        delegate: Button {
                            id: control
                            width: 114
                            property alias timerBtn: timer


                            checked: root.selected === index ? true : false

                            property string filterName: model.object.name
                            property string xLabel: model.object.xAxisLabel
                            property string yLabel: model.object.yAxisLabel
                            property int filterType: model.object.type
                            property real param: filterParameter.param
                            property string note: model.object.note
                            property string firstPlot: model.object.firstPlot
                            property string secondPlot: model.object.secondPlot


                            property real time: 0
                            property real dt: 1/root.sampleRateFreq


                            background: Rectangle {
                                id: back
                                anchors.fill:   control
                                color:          root.selected === index ? "yellow" : "grey"
                            }

                            contentItem : Text {
                                //                            id: name
                                anchors.centerIn: parent
                                text: filterName  //"sensor: " + index
                                //                        color:          control.checked ? "white" : "yellow"

                            }
                            onClicked: {
                                showFilterParameter(filterType)
                                param = filterParameter.param
                                console.log("param: ", param)
                                replotGraph(secondPlot, xLabel, yLabel, filterType, param,
                                            note, firstPlot, 1/root.sampleRateFreq )
                                root.selected = index
                                noteTextArea.text = "<b>Note:</b>" + note

                            }

                            Component.onCompleted: {
                                if(root.selected === index) {
                                    qCustomPlotWrapper.setupGraph(secondPlot, xLabel, yLabel, firstPlot)
                                    noteTextArea.text = "<b>Note:</b>" + note

                                }

                            }

                            Timer {
                                id: timer
                                running: root.selected === index ? true : false
                                repeat: root.selected === index ? true : false
                                interval: (1/root.sampleRateFreq) * 1000 // 10 milliseconds
                                //                                 property vector3d eulerVectorAngle

                                onTriggered: {
                                    if(filterType === FilterManager.EKFType) {
                                        var eulerAngles = filterManager.applyEKF();
//                                        console.log("filterManager.applyEKF: ", eulerAngles,
//                                                    eulerAngles.yaw, eulerAngles.pitch,
//                                                    eulerAngles.roll)

                                        root.time += parent.dt
                                        qCustomPlotWrapper.addPoint(root.time, eulerAngles.pitch, eulerAngles.roll)
                                    } else {
                                        root.time += parent.dt
                                        var volt = filterManager.getSensorData(filterType)
                                        currentAvgFilterValue = filterManager.applyFilter(volt, filterType)
                                        qCustomPlotWrapper.addPoint(root.time, volt, currentAvgFilterValue)
                                    }

                                }
                            }
                        }
                    }

                }

            } // control(Buttons)


            Rectangle {
                id: graphContainer
                width: parent.width - flickButton.width
                height: parent.height/2
                color: "blue"
                QCustomPlotWrapper {
                    id: qCustomPlotWrapper
                    anchors.fill: parent

                    onWidthChanged: {
                        updatePlotSize(parent.width, parent.height)
                    }
                    onHeightChanged: updatePlotSize(parent.width, parent.height)
                }

            } //graphContainer

            TextArea {
                id: noteTextArea
                textFormat: TextEdit.RichText
                wrapMode: TextEdit.WordWrap
                width: 160
                readOnly: true
                font.pointSize: 12
            }

        } //featureComp

    } //featureContainer

}
