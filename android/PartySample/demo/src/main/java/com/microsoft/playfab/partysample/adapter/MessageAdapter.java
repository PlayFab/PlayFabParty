package com.microsoft.playfab.partysample.adapter;

import android.support.annotation.NonNull;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.microsoft.playfab.partysample.demo.R;
import com.microsoft.playfab.partysample.model.ChatMessage;

import java.util.List;

public class MessageAdapter extends RecyclerView.Adapter<MessageAdapter.ViewHolder> {

    List<ChatMessage> messages;

    public MessageAdapter(List<ChatMessage> messages) {
        this.messages = messages;
    }

    @NonNull
    @Override
    public MessageAdapter.ViewHolder onCreateViewHolder(@NonNull ViewGroup viewGroup, int i) {
        Log.d("message adapter","onCreateViewHolder");
        View view = LayoutInflater.from(viewGroup.getContext()).inflate(R.layout.chat_message_item, viewGroup, false);
        final ViewHolder viewHolder = new ViewHolder(view);
        return viewHolder;
    }

    @Override
    public void onBindViewHolder(@NonNull MessageAdapter.ViewHolder viewHolder, int i) {
        Log.d("message adapter","onBindViewHolder");
        ChatMessage message = messages.get(i);
        viewHolder.nameView.setText(message.getName());
        viewHolder.msgView.setText(message.getMessage());
    }

    @Override
    public int getItemCount() {
        return messages != null ? messages.size() : 0;
    }

    static class ViewHolder extends RecyclerView.ViewHolder {
        TextView nameView;
        TextView msgView;

        public ViewHolder(View view) {
            super(view);
            nameView = view.findViewById(R.id.nameTextView2);
            msgView = view.findViewById(R.id.msgTextView);
        }
    }

    public void addMessage(String name, String text) {
        ChatMessage message = new ChatMessage();
        message.setMessage(text);
        message.setName(name);
        messages.add(message);
        this.notifyDataSetChanged();
    }

    public void clear() {
        messages.clear();
        this.notifyDataSetChanged();
    }
}
