import 'package:flutter/material.dart';
import 'inputPart.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  MyApp({super.key});

  static List<String> tab = ["Omer", "Carole"];

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
        title: "Chat App",
        home: Scaffold(
          appBar: AppBar(
            title: const Text("Chat App"),
          ),
          body: Column(children: [
            Column(
                children: tab.asMap().entries.map((value) {
              bool h = (value.key % 2) != 0;
              Color color = h ? Colors.green : Colors.yellow;
              return (UserMsg(value.value, color));
            }).toList()),
            InputPart(
              onTabChanged: (newTab) {
                tab = newTab;
                // setState(() {
                //   tab = newTab;
                // });
                // print("tab");
                // print(tab);
              },
            ),
          ]),
        ));
  }
}

class UserMsg extends StatelessWidget {
  final String msg;
  final Color color;

  const UserMsg(this.msg, this.color, {super.key});

  @override
  Widget build(BuildContext context) {
    return Container(
        color: color,
        child: Padding(
          padding: const EdgeInsets.all(16.0),
          child: Text(msg),
        ));
  }
}
